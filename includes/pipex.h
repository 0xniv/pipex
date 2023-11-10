/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:42 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/10 16:32:22 by nivi             ###   ########.fr       */
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
typedef struct s_pipex	t_pipex;
struct s_pipex
{
	char	**paths;
	char	**cmds;
	char	*cmd;
	char	*final;
};

typedef enum e_file_type
{
	INFILE,
	OUTFILE,
	IN = 0,
	OUT,
	ERR,
}			t_file_type;

/* =========================================================== */

/* functions */
int		full_error(char *str1, char *str2, char *str3, unsigned int retrn);
int		fork_time(char **argv, char **envp, int *fildes);
int		check_child(char *file, char *cmd, char **envp, int *fildes);
int		check_brother(char *file, char *cmd, char **envp, int *fildes);
int		build_cmd(char *argv, char **envp, char *path);
char	*get_env(char **envp);
char	*check_commands(char *cmd);
char	**get_command(char *argv);

#endif
