/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/05 05:10:09 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char **argv, int *pipedes, char **envp);
static void	parent_process(char **argv, int *pipedes, char **envp);

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
	/* use this code below in exec function to validade paths */
	// pype.path = get_paths(pype.path, envp);
	// pype.access = check_access(&pype, argv[2]);
	// pype.access = check_access(&pype, argv[3]);
	ft_free_split(pype.path);
	return (0);
}

static void	child_process(char **argv, int *pipedes, char **envp)
{
	int	fd;

	(void)envp;
	fd = open_file(argv[1], INFILE);
	dup2(fd, STDIN_FILENO);
	dup2(pipedes[1], STDOUT_FILENO);
	close(pipedes[0]);
	//make execution function to use with argv[2]
}

static void	parent_process(char **argv, int *pipedes, char **envp)
{
	int	fd;

	(void)envp;
	fd = open_file(argv[4], INFILE);
	dup2(fd, STDIN_FILENO);
	dup2(pipedes[0], STDOUT_FILENO);
	close(pipedes[1]);
	//make execution function to use with argv[3]
}
