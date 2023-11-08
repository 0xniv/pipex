/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/08 20:42:52 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	first_process(char **argv, int *pipedes, char **envp);
static void	second_process(char **argv, int *pipedes, char **envp);
static void	execution(char *cmd_arg, char **env);
void		make_pipe(char **argv, char **env);

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
		pype.fd_out = open_file(argv[1], OUTFILE);
		dup2(pype.fd_in, STD_INPUT);
	}
	while (pype.current_cmd < argc -2)
		make_pipe(argv, envp);
	waitpid(pype.pid_0, NULL, WNOHANG);
	waitpid(pype.pid_1, NULL, WNOHANG);
	close(pype.fd_in);
	close(pype.fd_out);
	return (0);
}

static void	first_process(char **argv, int *pipedes, char **envp)
{
	int	fd;

	fd = open_file(argv[1], INFILE);
	dup2(fd, STDIN_FILENO);
	dup2(pipedes[1], STDOUT_FILENO);
	close(pipedes[0]);
	close(pipedes[1]);
	close(fd);
	execution(argv[2], envp);
}

static void	second_process(char **argv, int *pipedes, char **envp)
{
	int	fd;

	fd = open_file(argv[4], OUTFILE);
	dup2(fd, STDOUT_FILENO);
	dup2(pipedes[0], STDIN_FILENO);
	close(pipedes[1]);
	close(pipedes[0]);
	close(fd);
	execution(argv[3], envp);
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

void	make_pipe(char **cmd, char **env)
{
	pid_t	pid;
	int		pipedes[2];

	if (pipe(pipedes) == -1)
		end();
	pid = fork();
	if (pid == -1)
		end();
	if (!pid)
		first_process(cmd, pipedes, env);
	pid = fork();
	if (pipedes[2])
		end();
	second_process(cmd, pipedes, env);

}
