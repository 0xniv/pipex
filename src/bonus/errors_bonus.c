/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:39:06 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/12 08:11:25 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	full_error(char *str1, char *str2, char *str3, unsigned int retrn)
{
	ft_putstr_fd("pipex: ", ERR);
	ft_putstr_fd(str1, ERR);
	ft_putstr_fd(str2, ERR);
	ft_putstr_fd(str3, ERR);
	ft_putstr_fd("\n", ERR);
	exit (retrn);
}

void	close_fd(t_pipex *bonus)
{
	int	i;

	i = 0;
	while (i < 2 * (bonus->args - 4 - bonus->aux))
		close(bonus->pipes[i++]);
}

void	free_strings(t_pipex *bonus)
{
	ft_free_split(bonus->paths_split);
	if (!bonus->cmd)
		ft_free_split(bonus->commands);
	ft_free_str(bonus->final);
	free(bonus->pipes);
	bonus->pipes = NULL;
	close(bonus->input);
	close(bonus->output);
}
