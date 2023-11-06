/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:42:34 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/06 09:58:04 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, t_file_type in_out)
{
	int		status;
	char	*err_msg;

	status = 0;
	if (in_out == INFILE)
		status = open(file, O_RDONLY);
	else if (in_out == OUTFILE)
		status = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (status == -1)
	{
		err_msg = ft_strjoin("pipex: ", file);
		perror(err_msg);
		free(err_msg);
		exit(errno);
	}
	return (status);
}
