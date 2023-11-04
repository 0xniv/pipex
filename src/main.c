/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 01:55:20 by nivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

int	main(int argc, char **argv, char **envp)
{
	// int	fd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// pid_t	pid3;
	// char	*path;
	(void)argv;
	(void)argc;
	(void)envp;
	// if (5 != argc)
	// {
	// 	ft_printf("%s\n", "Not In");
	// 	return (0);
	// }
	// if (pipe(fd) == -1)
	// 	return (1);
	// close(fd[0]);
	// close(fd[1]);
	char	**path;
	int		words;
	int		i;

	i = 0;
	words = 0;
	path = NULL;
	while (envp[i] != NULL) {
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL) {
			words = count_word(envp[i], ':');
			path = malloc(sizeof(char *) * words); 
			path = ft_split(envp[i] + 5, ':');
			break;
		}
		i++;
	}
	i = 0;
	while (path[i]) {
		printf("%s\n", path[i]);
		free(path[i]);
		i++;
	}
	free(path);
	
	return (0);
}