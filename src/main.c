/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 17:24:48 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	// int	fd[2];
	// pid_t	pid1;
	// pid_t	pid2;
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

	path = NULL;
	path = get_paths(path, envp);
	ft_free_split(path);
	
	return (0);
}
