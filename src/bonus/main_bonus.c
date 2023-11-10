/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/09 21:52:30 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	execution(char *cmd_arg, char **env);
static void	verify_fork(pid_t *pid, int *pipedes, char *cmd, char **env);
static void		close_fd(int *in, int *out);
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
	dup2(pype.fd_out, STDOUT_FILENO);
	execution(argv[pype.current_cmd], envp);
	printf("\n aqui eu cheguei? main\n");
	close_fd(&pype.fd_in, &pype.fd_out);
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
	pid_t	pid_2;
	int		pipedes[2];

	if (pipe(pipedes) == -1)
		end();
	pid = fork();
	printf("\ncheguei aqui ??\n");
	verify_fork(&pid, pipedes, cmd, env);
	pid_2 = fork();
	verify_fork(&pid_2, pipedes, cmd, env);
	printf("\ncheguei aqui??2");
	waitpid(pid, NULL, 0);
	waitpid(pid_2, NULL, 0);
}

static void	verify_fork(pid_t *pid, int *pipedes, char *cmd, char **env)
{
	if (*pid == -1)
		end();
	if (*pid == 0)
	{
		close(pipedes[0]);
		dup2(pipedes[1], STDOUT_FILENO);
		execution(cmd, env);
	}
	else
	{
		close(pipedes[1]);
		dup2(pipedes[0], STD_INPUT);
	}
}

static void	close_fd(int *in, int *out)
{
	close(*in);
	close(*out);
}
