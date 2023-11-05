/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:42 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/05 04:26:18 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* libft */
# include "../lib/libft/includes/libft.h"

/* ft_printf */
# include "../lib/ft_printf/includes/ft_printf.h"

/* both to open */
# include <sys/stat.h>
# include <fcntl.h>

/* close, read, write, access, dup, dup2, execve, fork, pipe, unlink */
# include <unistd.h>

/* malloc and free, exit */
# include <stdlib.h>

/* perror */
# include <stdio.h>
# include <errno.h>

/* strerror */
# include <string.h>

/* wait, waitpid */
# include <sys/wait.h>

/* =========================================================== */

/* defines */

# define ERRFD "Error in fd creation"

/* =========================================================== */

/* structs */
typedef struct s_pipe	t_pipe;
struct s_pipe
{
	int		fd[2];
	int		access;
	pid_t	pid;
	size_t	pos;
	char	**path;
	char	**cmds;
};

/* =========================================================== */

/* functions */
void	invalid_args();
char	**get_paths(char **path, char **envp);
int		check_access(t_pipe	**pipe, char *command);
int		count_word(const char *s, char c);

#endif
