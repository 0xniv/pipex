/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/12 22:17:33 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	child_in(t_pipex bonus, char *argv, char **envp)
{
	dup2(bonus.input, 0);
	dup2(bonus.pipes[1], 1);
	close_fd(&bonus);
	bonus.paths = get_env(envp);
	bonus.paths_split = ft_split(bonus.paths, ':');
	bonus.commands = get_command(argv);
	bonus.final = check_commands(bonus.commands[0]);
	bonus.cmd = search_path(bonus.final, bonus.paths_split);
	free_strings(&bonus);
	if (!bonus.cmd)
		return (full_error("command not found: ", argv, "", 127));
	if (execve(bonus.cmd, bonus.commands, envp) < 0)
	{
		ft_free_str(bonus.cmd);
		ft_free_split(bonus.commands);
		return (full_error("execve error", "", "", 127));
	}
	return (IN);
}

int	child_mid(t_pipex bonus, char *argv, char **envp)
{
	dup2(bonus.pipes[2 * bonus.index - 2], IN);
	dup2(bonus.pipes[2 * bonus.index + 1], OUT);
	close_fd(&bonus);
	bonus.paths = get_env(envp);
	bonus.paths_split = ft_split(bonus.paths, ':');
	bonus.commands = get_command(argv);
	bonus.final = check_commands(bonus.commands[0]);
	bonus.cmd = search_path(bonus.final, bonus.paths_split);
	free_strings(&bonus);
	if (!bonus.cmd)
		return (full_error("command not found: ", argv, "", 127));
	if (execve(bonus.cmd, bonus.commands, envp) < 0)
	{
		ft_free_str(bonus.cmd);
		ft_free_split(bonus.commands);
		return (full_error("execve error", "", "", 127));
	}
	return (IN);
}

int	child_out(t_pipex bonus, char *argv, char **envp)
{
	dup2(bonus.pipes[2 * bonus.index - 2], IN);
	dup2(bonus.output, OUT);
	close_fd(&bonus);
	bonus.paths = get_env(envp);
	bonus.paths_split = ft_split(bonus.paths, ':');
	bonus.commands = get_command(argv);
	bonus.final = check_commands(bonus.commands[0]);
	bonus.cmd = search_path(bonus.final, bonus.paths_split);
	free_strings(&bonus);
	if (!bonus.cmd)
		return (full_error("command not found: ", argv, "", 127));
	if (execve(bonus.cmd, bonus.commands, envp) < 0)
	{
		ft_free_str(bonus.cmd);
		ft_free_split(bonus.commands);
		return (full_error("execve error", "", "", 127));
	}
	return (IN);
}

int	make_pipes(t_pipex *bonus)
{
	int	i;

	bonus->pipes = (int *)malloc(sizeof(int) * 2 * (bonus->args - 4 - \
	bonus->aux));
	if (!bonus->pipes)
		return (full_error("pipe error", "", "", OUT));
	i = 0;
	while (i < (bonus->args - 4 - bonus->aux))
	{
		if (pipe(bonus->pipes + (2 * i)) < 0)
			return (full_error("pipe error", "", "", OUT));
		i++;
	}
	return (0);
}
