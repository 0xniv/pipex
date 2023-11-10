/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:42 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/10 12:45:14 by nivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

/* =========================================================== */

/* structs */
typedef struct s_pipe	t_pipe;
struct s_pipe
{
	int		retrn;
	int		fd[2];
	int		status;
	int		file;
	pid_t	pid_p;
	pid_t	pid_c;
	size_t	pos;
	char	*path;
};

typedef enum e_file_type
{
	INFILE,
	OUTFILE,
}			t_file_type;

/* =========================================================== */

/* functions */
void	invalid_args(void);
void	end(void);
void	end_pipe(char *file);
char	**get_paths(char **path, char **envp);
int		check_access(t_pipe	**pipe, char *command);
int		open_file(char *file, t_file_type in_out);

#endif
