/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:25:32 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/03 17:23:15 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char *const envp[])
{
	int	fd[2];
	pid_t	pid1;
	pid_t	pid2;
	pid_t	pid3;
	(void)argv;
	if (5 != argc)
	{
		ft_printf("%s\n", "Not In");
		return (0);
	}
	if (pipe(fd) == -1)
		return (1);
	pid3 = fork();
	if (pid3 < 0)
		return (2);
	if (pid3 == 0)
	{

	}
		// Usar strnstr para verificar o retorno
		// guardar o path retornado na variabel path
		// fazer o execve executar o path
	return (0);
}