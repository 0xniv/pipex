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

int main(int argc, char **argv, char const *envp[])
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		pid3;
	char	**args;
	char	*path;

	(void)argv;

	if (5 != argc)
	{
		ft_printf("%s\n", "Not In");
		return (0);
	}
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


	return (0);
}