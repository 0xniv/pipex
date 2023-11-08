/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:39:06 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/08 20:23:41 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	invalid_args(void)
{
	char	*err[14];
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
	err[8] = "\nIf you're trying <here_doc>: \n";
	err[9] = "LIMITER: The path to the input file.";
	err[10] = "<cmd[1, 2, ..., N]>: The commands to be executed.";
	err[11] = "<path_to_outfile>: The path to the output file.\n";
	err[12] = "Ex: ./pipex here_doc LIMITER \"grep hello\" sort output.txt";
	err[13] = NULL;
	while (err[index])
		ft_putendl_fd(err[index++], STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	end(void)
{
	perror(NULL);
	exit(errno);
}
