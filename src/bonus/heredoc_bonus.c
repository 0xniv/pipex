/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:36:40 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/12 16:14:32 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	check_child_here(t_pipex bonus, char **argv, char **envp);

int	heredoc(char **argv, char **envp, int argc)
{
	t_pipex	doc;
	char	*buf;
	int		fd;

	doc.args = argc;
	fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0000644);
	if (fd < 0)
		return (full_error("here_doc file error", " : ", strerror(errno), OUT));
	while (1)
	{
		write(OUT, "heredoc> ", 9);
		buf = get_next_line(0);
		if (ft_strlen(buf) == (ft_strlen(argv[2]) + 1) && \
		(!ft_strncmp(buf, argv[2], ft_strlen(argv[2]))))
			break ;
		ft_free_str(buf);
	}
	ft_free_str(buf);
	doc.ret = files_open(&doc, argv);
	doc.index = 0;
	doc.aux = 1;
	doc.ret = check_child_here(doc, argv, envp);
	close(fd);
	unlink(argv[1]);
	return (doc.ret);
}

int	check_child_here(t_pipex bonus, char **argv, char **envp)
{
	make_pipes(&bonus);
	while (bonus.index < (bonus.args - bonus.aux - 3))
	{
		bonus.pid = fork();
		if (bonus.pid < 0)
			return (full_error("fork failed", "", "", OUT));
		else if (bonus.pid == 0)
		{
			if (bonus.index == 0)
				child_in(bonus, argv[2 + bonus.aux], envp);
			else if (bonus.index == bonus.args - 4 - bonus.aux)
				child_out(bonus, argv[2 + bonus.index + bonus.aux], envp);
			else
				child_mid(bonus, argv[2 + bonus.index + bonus.aux], envp);
		}
		bonus.index++;
	}
	close_fd(&bonus);
	waitpid(-1, &bonus.status, IN);
	return (end_struct(&bonus));
}
