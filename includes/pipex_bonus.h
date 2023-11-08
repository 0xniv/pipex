/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:42 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/08 13:24:41 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* libft */
# include "../lib/libft/includes/libft.h"

/* ft_printf */
# include "../lib/ft_printf/includes/ft_printf_bonus.h"

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
# define HERE_STR "here_doc"

/* =========================================================== */

/* structs */
typedef struct s_pipe	t_pipe;
struct s_pipe
{
	int		fd_in;
	int		fd_out;
	int		access;
	pid_t	pid_0;
	pid_t	pid_1;
	size_t	pos;
	char	**path;
	char	**cmd;
	char	*current_cmd;
};

typedef enum e_file_type
{
	INFILE,
	OUTFILE,
	F_APPEND,
	INIT_CMD = 2,
	HERE_CMD,
	STD_INPUT = 0,
}			t_file_type;

/* =========================================================== */

/* functions */
void	invalid_args(void);
void	here_doc(char **argv);
void	end(void);
char	**get_paths(char **path, char **envp);
int		check_access(t_pipe	**pipe, char *command);
int		open_file(char *file, t_file_type in_out);

#endif
