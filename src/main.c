/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 19:19:07 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe;
	(void)argv;
	(void)envp;
	pipe.path = NULL;
	if (5 != argc)
		invalid_args();
	// if (pipe(fd) == -1)
	// 	return (1);
	// close(fd[0]);
	// close(fd[1]);

	pipe.path = get_paths(pipe.path, envp);
	ft_free_split(pipe.path);
	
	return (0);
}
