/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/05 00:08:39 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof(t_pipe));
	if (5 != argc)
		invalid_args();
	// if (pipe(fd) == -1)
	// 	return (1);
	// close(fd[0]);
	// close(fd[1]);

	pipe->path = get_paths(pipe->path, envp);
	pipe->access = check_access(pipe, &argv[2]);
	ft_free_split(pipe->path);
	free(pipe);
	return (0);
}
