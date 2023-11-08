/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:35:21 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/08 20:23:41 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	manage_here_doc(char **argv, int *pipedes)

char	**get_paths(char **path, char **envp)
{
	int	index;

	index = 0;
	while (envp[index] != NULL)
	{
		if (ft_strnstr(envp[index], "PATH=", 5) != NULL)
			path = ft_split(envp[index] + 5, ':');
		index++;
	}
	index = 0;
	while (path[index] != NULL)
	{
		path[index] = ft_strjoin(path[index], "/");
		index++;
	}
	if (pype->path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_free_split(path);
		exit(127);
	}
	return (path);
}

void	here_doc(char **argv)
{
	int	pipedes[2];
	pid_t	pid;

	if (pipe(pipedes) == -1)
		end();
	pid = fork();
	if (pid == -1)
		end();
	if (!pid)	
		manage_here_doc(argv, pipedes);
}

static void	manage_here_doc(char **argv, int *pipedes)
{
	char	*line;
	char	*limiter;
	size_t	limiter_len;

	limiter = argv[2];
	limiter_len = ft_strlen(argv[2]);
	close(pipedes[0]);
	while (1)
	{
		line = get_next_line(STD_INPUT);
		if (ft_strncmp(line, limiter, limiter_len) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, pipedes[1]);
		free(line);
	}
}
