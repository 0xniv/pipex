/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:07:05 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 23:55:21 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(t_pipe *pipe, char **command)
{
	pipe->access = 0;
	while (pipe->path[pipe->pos] != NULL)
	{
		pipe->path[pipe->pos] = ft_strjoin(pipe->path[pipe->pos], command[2]);
		pipe->access = access(pipe->path[pipe->pos], X_OK | F_OK);
		if (pipe->access == 0)
		{
			printf("is a executable file\n");
			return (pipe->access) ;
		}
		pipe->pos++;
	}
	return (pipe->access);
}
