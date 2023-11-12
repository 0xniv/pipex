/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/12 05:32:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	start_struct(t_pipex *bonus, int argc, char **argv);
int	check_child(t_pipex bonus, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	bonus;

	if (argc < 5)
		return (full_error("4 arguments needed: ", "", "", OUT));
	if (!ft_strncmp(argv[1], "here_doc", 8))
		return (heredoc(argv, envp, argc));
	bonus.ret = start_struct(&bonus, argc, argv);
	bonus.ret = check_child(bonus, argv, envp);
	return (bonus.ret);
}

int	start_struct(t_pipex *bonus, int argc, char **argv)
{
	int	ret;

	ret = 0;
	bonus->args = argc;
	ret = files_open(bonus, argv);
	if (ret)
		return (ret);
	bonus->aux = 0;
	ret = do_pipes(bonus);
	if (ret)
		return (ret);
	bonus->index = 0;
	return (ret);
}

int	check_child(t_pipex bonus, char **argv, char **envp)
{
	while (bonus.index < (bonus.args - 3))
	{
		bonus.pid = fork();
		if (bonus.pid < 0)
			return (full_error("fork failed", "", "", OUT));
		else if (bonus.pid == 0)
		{
			if (bonus.index == 0)
				//TODO child_in
			else if (bonus.index == bonus.args - 4)
				//TODO child_out
			else
				//todo child_mid
		}
		bonus.index++;
	}
	//TODO close_fd
	waitpid(-1, &bonus.status, IN);
	return (end_struct(&bonus));
}

int	check_brother(char *file, char *cmd, char **envp, int *fildes)
{
	int		file_brother;
	char	*path;

	file_brother = open(file, O_TRUNC | O_CREAT | O_RDWR, 0000666);
	if (file_brother < 0)
		return (full_error(file, ": ", strerror(errno), OUT));
	dup2(fildes[0], 0);
	close(fildes[1]);
	close(fildes[0]);
	dup2(file_brother, 1);
	path = get_env(envp);
	return (build_cmd(cmd, envp, path));
}

char	*get_env(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
