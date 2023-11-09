/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:40:28 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/09 10:05:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(t_pipe **pipe, char *command)
{
	while ((*pipe)->path[(*pipe)->pos] != NULL)
	{
		(*pipe)->path[(*pipe)->pos] = \
		ft_strjoin((*pipe)->path[(*pipe)->pos], command);
		(*pipe)->access = access((*pipe)->path[(*pipe)->pos], X_OK | F_OK);
		if ((*pipe)->access == 0)
			return ((*pipe)->access);
		(*pipe)->pos++;
	}
	if ((*pipe)->access == -1)
	{
		ft_putstr_fd("pipe: command not found: ", STDERR_FILENO);
		ft_putendl_fd(command, STDERR_FILENO);
		ft_free_split((*pipe)->path);
		free((*pipe));
		invalid_args();
	}
	if ((*pipe)->path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putendl_fd(command, STDERR_FILENO);
		ft_free_split((*pipe)->path);
		exit(127);
	}
	return ((*pipe)->access);
}
