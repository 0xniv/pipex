/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 05:32:55 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/12 13:20:49 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	*get_env(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
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
			temp = NULL;
			aux = ft_strdup(final[0]);
			ft_free_split(final);
			return (aux);
		}
		++i;
	}
	return (temp);
}

char	*search_path(char *final, char **paths)
{
	char	*temp;
	char	*cmd;
	int		i;

	if (access(final, F_OK | X_OK) == 0)
	{
		cmd = ft_strdup(final);
		return (cmd);
	}
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(temp, final);
		ft_free_str(temp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		ft_free_str(cmd);
		i++;
	}
	return (NULL);
}
