/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:42:34 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/08 17:04:21 by vde-frei         ###   ########.fr       */
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
	return (status);
}
