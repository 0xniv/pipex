/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:35:21 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/07 16:18:11 by nivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	return (path);
}
