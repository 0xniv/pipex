/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:35:21 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/05 04:47:11 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_word(const char *s, char c)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			words++;
			while (s[index] != c && s[index] != '\0')
				index++;
		}
		else
			index++;
	}
	return (words);
}

char	**get_paths(char	**path, char **envp)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while (envp[index] != NULL)
	{
		if (ft_strnstr(envp[index], "PATH=", 5) != NULL)
		{
			words = count_word(envp[index], ':');
			path = ft_split(envp[index] + 5, ':');
			break ;
		}
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
