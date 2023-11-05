/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:39:06 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/05 04:05:29 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	invalid_args()
{
	char	*err[9];
	size_t	index;

	index = 0;
	err[0] = "Invalid arguments:\n";
	err[1] = "Use: ./pipex <infile_path> <cmd1> <cmd2> <outfile_path>\n";
	err[2] = "Provide correct parameters.\n";
	err[3] = "<infile_path>: Path to the input file.\n";
	err[4] = "<cmd1>:  First command to be executed.\n";
	err[5] = "<cmd2>:  Second command to be executed.\n";
	err[6] = "<outfile_path>: Path to the output file.\n";
	err[7] = "E.g., ./pipex infile \"ls -l\" \"wc -l\" outfile\n";
	err[8] = NULL;
	while (err[index])
		ft_putendl_fd(err[index++], STDERR_FILENO);
	exit(EXIT_FAILURE);
}
