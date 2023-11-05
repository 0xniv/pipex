/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/05 04:32:40 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_pipe *pype, char **argv, char **envp);
static void	parent_process(t_pipe *pype, char **argv, char **envp);

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
		child_process(argv, pype.fd,envp);
	waitpid(pype.pid, NULL, WNOHANG);
	parent_process(&pype, argv, envp);
	pype.path = get_paths(pype.path, envp);
	pype.access = check_access(&pype, argv[2]);
	pype.access = check_access(&pype, argv[3]);
	ft_free_split(pype.path);
	return (0);
}
static void	child_process(char **argv, int *fd, char **envp)
{
}
static void	parent_process(t_pipe *pype, char **argv, char **envp)
{
	pype->path = get_paths(pype->path, envp);
	pype->access = check_access(&pype, argv[2]);
	pype->access = check_access(&pype, argv[3]);
	ft_free_split(pype->path);
	free(pype);
}
