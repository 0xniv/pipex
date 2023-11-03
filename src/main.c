/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/03 01:13:31 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

<<<<<<< HEAD
int main(int argc, char **argv, char const *envp[])
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		pid3;
	char	**args;
	char	*path;

	(void)argv;

=======
int	main(int argc, char **argv, char *const envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;
	// int	pid3;
	char	*path;
	// char	**flags;
	(void)argv;
>>>>>>> 30b0b63b6be3661b65a17411ae53710d6b2405d8
	if (5 != argc)
	{
		ft_printf("%s\n", "Not In");
		return (0);
	}
<<<<<<< HEAD
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		pid3 = fork();
		if (pid3 == -1)
			return (3);
		// Usar strnstr para verificar o retorno
		// guardar o path retornado na variabel path
		// fazer o execve executar o path
		execve(path, argv[3], envp);
		
		dup2(fd[1], STDOUT_FILENO);
		close(0);
		close(1);
	}
	pid_t	pid;


=======
	if (pipe(fd) == -1)	
		return (1);
	pid1 = fork();
	if (pid1 < 0)	
		return (2);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/where", &argv[3], envp);

	}
	pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0)
	{
		path = malloc(ft_strlen(argv[3]));
		read(1, path, ft_strlen(argv[3]));
		close(fd[0]);
		close(fd[1]);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	ft_printf("%s\n", "In");
>>>>>>> 30b0b63b6be3661b65a17411ae53710d6b2405d8
	return (0);
}