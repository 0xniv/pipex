/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/12 08:12:40 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	start_struct(t_pipex *bonus, int argc, char **argv);
int	check_child(t_pipex bonus, char **argv, char **envp);
int	files_open(t_pipex *bonus, char **argv);
int	end_struct(t_pipex *bonus);

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

int	files_open(t_pipex *bonus, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		bonus->input = open(argv[1], O_RDONLY);
		if (bonus->input < 0)
			return (full_error("input file error", ": ", strerror(errno), OUT));
		bonus->output = open(argv[bonus->args - 1], O_APPEND | O_CREAT | \
		O_RDWR, 0000666);
		if (bonus->output < 0)
			return (full_error(argv[bonus->args - 1], ": ", \
			strerror(errno), 1));
	}
	else
	{
		bonus->input = open(argv[1], O_RDONLY);
		if (bonus->input < 0)
			return (full_error(argv[1], ": ", strerror(errno), OUT));
		bonus->output = open(argv[bonus->args - 1], O_TRUNC | O_CREAT | \
		O_RDWR, 0000666);
		if (bonus->output < 0)
			return (full_error(argv[bonus->args - 1], ": ", strerror(errno), \
			OUT));
	}
	return (IN);
}

int	end_struct(t_pipex *bonus)
{
	free(bonus->pipes);
	bonus->pipes = NULL;
	close(bonus->input);
	close(bonus->output);
	if (WIFEXITED(bonus->status))
		return (WEXITSTATUS(bonus->status));
	return (IN);
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
				child_in(bonus, argv[2], envp);
			else if (bonus.index == bonus.args - 4)
				child_out(bonus, argv[2 + bonus.index], envp);
			else
				child_mid(bonus, argv[2 + bonus.index], envp);
		}
		bonus.index++;
	}
	close_fd(&bonus);
	waitpid(-1, &bonus.status, IN);
	return (end_struct(&bonus));
}
