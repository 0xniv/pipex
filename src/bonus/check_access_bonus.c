/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:40:28 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/08 20:23:41 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

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
	return ((*pipe)->access);
}
