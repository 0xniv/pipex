/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/06 16:06:57 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char **argv, int *pipedes, char **envp);
static void	parent_process(char **argv, int *pipedes, char **envp);
static void	execution(char *cmd_arg, char **env);

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pype;

	if (5 != argc)
		invalid_args();
	if (pipe(pype.fd) == -1)
	{
		perror(NULL);
		exit(errno);
	}
	pype.pid = fork();
	if (pype.pid == -1)
	{
		perror(NULL);
		exit(errno);
	}
	if (!pype.pid)
		child_process(argv, pype.fd, envp);
	waitpid(pype.pid, NULL, WNOHANG);
	parent_process(argv, pype.fd, envp);
	return (0);
}

static void	child_process(char **argv, int *pipedes, char **envp)
{
	int	fd;

	fd = open_file(argv[1], INFILE);
	dup2(fd, STDIN_FILENO);
	dup2(pipedes[1], STDOUT_FILENO);
	close(pipedes[0]);
	close(fd);
	execution(argv[2], envp);
}

static void	parent_process(char **argv, int *pipedes, char **envp)
{
	int	fd;

	fd = open_file(argv[4], OUTFILE);
	dup2(fd, STDOUT_FILENO);
	dup2(pipedes[0], STDIN_FILENO);
	close(pipedes[1]);
	close(fd);
	execution(argv[3], envp);
}

static void	execution(char *cmd_arg, char **env)
{
	t_pipe	*pype;
	char	**cmd_n_flags;

	pype = ft_calloc(1, sizeof(t_pipe *));
	pype->path = get_paths(pype->path, env);
	cmd_n_flags = ft_split(cmd_arg, ' ');
	if (pype->path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putendl_fd(cmd_n_flags[0], STDERR_FILENO);
		ft_free_split(cmd_n_flags);
		exit(127);
	}
	pype->access = check_access(&pype, cmd_n_flags[0]);
	if (pype->access == 0)
		execve(pype->path[pype->pos], cmd_n_flags, env);
	free(*(pype)->path);
	ft_free_split(cmd_n_flags);
	perror(NULL);
	exit(errno);
}
