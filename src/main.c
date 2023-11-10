/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/10 16:12:44 by nivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		fork_time(char **argv, char **envp, int *fildes);
int		check_child(char *file, char *cmd, char **envp, int *fildes);
int		check_brother(char *file, char *cmd, char **envp, int *fildes);
char	*get_env(char **envp);

int	main(int argc, char **argv, char **envp)
{
	int	fildes[2];
	int	retrn;

	if (argc != 5)
		return (full_error("4 arguments needed: ", "", "", OUT));
	if (pipe(fildes) < 0)
		return (full_error("pipe error", "", "", OUT));
	retrn = fork_time(argv, envp, fildes); 
	return (retrn);
}

int	fork_time(char **argv, char **envp, int *fildes)
{
	int		status;
	pid_t	pid_c;
	pid_t	pid_b;

	pid_c = fork();
	if (pid_c == -1)
		return (full_error("fork failed", "", "", OUT));
	else if (pid_c == 0)
		check_child(argv[1], argv[2], envp, fildes);
	pid_b = fork();
	if (pid_b == -1)
		return (full_error("fork failed", "", "", OUT));
	else if (pid_b == 0)
		check_child(argv[4], argv[3], envp, fildes);
	close(fildes[0]);
	close(fildes[1]);
	waitpid(pid_c, NULL, 0);
	waitpid(pid_b, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (IN);
}

int	check_child(char *file, char *cmd, char **envp, int *fildes)
{
	int		file;
	char	*path;

	file = open(file, O_RDONLY);
	if (file < 0)
		return (full_error(file, ": ", strerror(errno), OUT));
	dup2(fildes[1], 1);
	close(fildes[0]);
	close(fildes[1]);
	dup2(file, 0);
	path = get_path(envp);
	return (build_cmd(cmd, envp, path));
}

int	check_brother(char *file, char *cmd, char **envp, int *fildes)
{
	int		file;
	char	*path;

	file = open(file, O_TRUNC | O_CREAT | O_RDWR, 00666);
	if (file < 0)
		return (full_error(file, ": ", strerror(errno), OUT));
	dup2(fildes[0], 0);
	close(fildes[1]);
	close(fildes[0]);
	dup2(file, 1);
	path = get_path(envp);
	return (build_cmd(cmd, envp, path));
}

char	*get_env(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
