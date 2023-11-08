/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:42:34 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/08 15:50:58 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, t_file_type in_out)
{
	int		status;

	status = 0;
	if (in_out == INFILE)
		status = open(file, O_RDONLY);
	else if (in_out == OUTFILE)
		status = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// if (status == -1)
	// {
	// 	ft_putstr_fd("pipex: ", STDERR_FILENO);
	// 	ft_putendl_fd(file, STDERR_FILENO);
	// }
	return (status);
}
