/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 21:48:11 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe;
	pipe.path = NULL;
	pipe.pos = 0;
	(void)argv;
	if (5 != argc)
		invalid_args();
	// if (pipe(fd) == -1)
	// 	return (1);
	// close(fd[0]);
	// close(fd[1]);

	pipe.path = get_paths(pipe.path, envp);
	while (pipe.path[pipe.pos] != NULL)
	{
		pipe.path[pipe.pos] = ft_strjoin(pipe.path[pipe.pos], argv[2]);
		pipe.access = access(pipe.path[pipe.pos], F_OK);
		if (pipe.access == 0)
		{
			printf("is a executable file\n");
			break ;
		}
		pipe.pos++;
	}
	ft_free_split(pipe.path);
	return (0);
}
