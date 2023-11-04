/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/03 23:05:04 by vde-frei         ###   ########.fr       */
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
	char	teh[3][50] = { "oi", "test", "PATH=/nfs/s/a:/nfs/ab/cs:/nfs/a/as" };
	int		words;
	int		pos = 0;

	words = 0;
	path = NULL;
	while (pos <= 3) {
		if (ft_strnstr(*teh, "PATH=", 5) != NULL) {
			words = count_word(*teh, ':');
			path = malloc(sizeof(char *) * words); 
			path = ft_split(*teh + 5, ':');
			break;
		}
		pos++;
	}
	while (*path) {
		printf("%s\n", *path);
		free(*path);
		path++;
	}
	free(path);
	return (0);
}