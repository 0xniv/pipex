/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:31:42 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/12 23:21:02 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* libft */
# include "../lib/libft/includes/libft.h"

/* both to open */
# include <sys/stat.h>
# include <fcntl.h>

/* close, read, write, access, dup, dup2, execve, fork, pipe, unlink */
# include <unistd.h>

/* malloc and free, exit */
# include <stdlib.h>

/* type libs */
# include <stddef.h>
# include <sys/types.h>

/* perror */
# include <stdio.h>
# include <errno.h>

/* strerror */
# include <string.h>

/* wait, waitpid */
# include <sys/wait.h>

/* =========================================================== */

/* structs */
typedef struct s_pipex	t_pipex;
struct s_pipex
{
	int		args;
	int		input;
	int		output;
	int		index;
	int		ret;
	int		status;
	int		aux;
	int		*pipes;
	char	*paths;
	char	**paths_split;
	char	*cmd;
	char	**commands;
	char	*final;
	pid_t	pid;
	pid_t	pid_c;
	pid_t	pid_b;
};

typedef enum e_file_type
{
	IN,
	OUT,
	ERR,
}			t_file_type;

/* =========================================================== */

/* functions */
int		full_error(char *str1, char *str2, char *str3, unsigned int retrn);
int		heredoc(char **argv, char **envp, int argc);
int		start_struct(t_pipex *bonus, int argc, char **argv);
int		check_child(t_pipex bonus, char **argv, char **envp);
int		files_open(t_pipex *bonus, char **argv);
int		end_struct(t_pipex *bonus);
int		child_in(t_pipex bonus, char *argv, char **envp);
int		child_mid(t_pipex bonus, char *argv, char **envp);
int		child_out(t_pipex bonus, char *argv, char **envp);
int		make_pipes(t_pipex *bonus);
void	close_fd(t_pipex *bonus);
void	free_strings(t_pipex *bonus);
char	**get_command(char *argv);
char	*get_env(char **envp);
char	*check_commands(char *cmd);
char	*search_path(char *final, char **paths);

#endif
