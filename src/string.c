/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:35:21 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/10 16:32:58 by nivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_command(char *argv);
char	*check_commands(char *cmd);

int	build_cmd(char *argv, char **envp, char *path)
{
	t_pipex	pipex;

	if (!argv)
		return (full_error("Parsing command fails:", strerror(errno), "", OUT));
	pipex.paths = ft_split(path, ':');
	pipex.cmds = get_command(argv);
	pipex.final = check_command(pipex.cmds[0]);
	pipex.cmd = search_path(pipex.final, pipex.paths);
	ft_free_split(pipex.paths);
	free(pipex.final);
	if (!pipex.cmd)
	{
		ft_free_split(pipex.cmds);
		return (full_error("command not found ", argv, "", 127));
	}
	if (execve(pipex.cmd, pipex.paths, envp) < 0)
	{
		free(pipex.cmd);
		ft_free_split(pipex.cmds);
		return (full_error("execve failed", "", "", 127));
	}
	return (IN);
}

char	**get_command(char *argv)
{
	int			i;
	char		**cmds;

	i = ft_strlen(argv);
	while (argv[i] != 0x27 && argv[i] != 0x22 && i != 0)
		--i;
	if (i == 0)
		cmds = ft_split(argv, ' ');
	else
	{
		if (argv[i] == 39)
			cmds = ft_split(argv, 0x27);
		else
			cmds = ft_split(argv, 0x22);
	}
	return (cmds);
}

char	*check_commands(char *cmd)
{
	char	*temp;
	char	*aux;
	char	**final;
	size_t	i;

	i = 0;
	temp = ft_strdup(cmd);
	while (temp[i] != '\0')
	{
		if (temp[i] == ' ')
		{
			final = ft_split(temp, ' ');
			free(temp);
			aux = ft_strdup(final[0]);
			ft_free_split(final);
			return (aux);
		}
		++i;
	}
	return (temp);
}
