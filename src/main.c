/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/10 13:01:02 by nivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void fork_time(char **argv, char **envp, int *fildes);
static void	second_process(char **argv, int *pipedes, char **envp);
static void	execution(char *cmd_arg, char **env);

int	main(int argc, char **argv, char **envp)
{
	int	fildes[2];
	int	retrn;

	if (argc != 5) //TODO full_error
		return (full_error("4 arguments needed: ", "", "", STDOUT_FILENO));
	if (pipe(fildes) < 0)	
		return (full_error("pipe error", "", "", STDOUT_FILENO));
	retrn = fork_time(argv, envp, fildes); 
	return (retrn);
}

static void	fork_time(char **argv, char **envp, int *fildes)
{
	int	status;
	pid_t	pid_c;
	pid_t	pid_b;

	pid_c = fork();
	if (pid_c == - 1)
		return (full_error("fork failed", "", "", STDOUT_FILENO));

}
