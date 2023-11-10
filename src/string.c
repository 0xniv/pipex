/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:35:21 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/09 15:51:08 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **path, char **envp)
{
	int	index;

	index = -1;
	while (envp[++index] != NULL)
		if (ft_strnstr(envp[index], "PATH=", 5) != NULL)
			path = ft_split(envp[index] + 5, ':');
	index = -1;
	while (path[++index] != NULL)
		path[index] = ft_strjoin(path[index], "/");
	return (path);
}
