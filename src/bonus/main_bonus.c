/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/09 12:05:50 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	execution(char *cmd_arg, char **env);
static void	verify_fork(pid_t pid, int *pipedes);
void		make_pipe(char *argv, char **env);

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pype;

	if (5 < argc)
		invalid_args();
	if (ft_strncmp(argv[1], HERE_STR, ft_strlen(HERE_STR)) == 0)
	{
		if (argc < 6)
			invalid_args();
		pype.current_cmd = HERE_CMD;
		pype.fd_out = open_file(argv[argc - 1], F_APPEND);
		here_doc(argv);
	}
	else
	{
		pype.current_cmd = INIT_CMD;
		pype.fd_in = open_file(argv[1], INFILE);
		pype.fd_out = open_file(argv[argc - 1], OUTFILE);
		dup2(pype.fd_in, STD_INPUT);
	}
	while (pype.current_cmd < argc -2)
		make_pipe(argv[pype.current_cmd++], envp);	
	close(pype.fd_in);
	close(pype.fd_out);
	return (0);
}

static void	execution(char *cmd_arg, char **env)
{
	t_pipe	*pype;
	char	**cmd_n_flags;

	pype = ft_calloc(1, sizeof(t_pipe));
	pype->path = get_paths(pype->path, env);
	cmd_n_flags = ft_split(cmd_arg, ' ');
	pype->access = check_access(&pype, cmd_n_flags[0]);
	if (pype->access == 0)
		execve(pype->path[pype->pos], cmd_n_flags, env);
	free(*(pype)->path);
	ft_free_split(cmd_n_flags);
	perror(NULL);
	exit(errno);
}

void	make_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		pipedes[2];

	if (pipe(pipedes) == -1)
		end();
	pid = fork();
	verify_fork(pid, pipedes);
	execution(cmd, env);	
	waitpid(pid, NULL, WNOHANG);
	pid = fork();
	verify_fork(pid, pipedes);
	waitpid(pid, NULL, WNOHANG);
}

static void	verify_fork(pid_t pid, int *pipedes)
{
	if (pid == -1)
		end();
	if (!pid)
	{
		close(pipedes[0]);
		dup2(pipedes[1], STDOUT_FILENO);
	}
	else
	{
		close(pipedes[1]);
		dup2(pipedes[0], STD_INPUT);
	}
}
