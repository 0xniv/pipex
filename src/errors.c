/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivi <nivi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:39:06 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/10 15:18:57 by nivi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	full_error(char *str1, char *str2, char *str3, unsigned int retrn)
{
	ft_putstr_fd("pipex: ", ERR);
	ft_putstr_fd(str1, ERR);
	ft_putstr_fd(str2, ERR);
	ft_putstr_fd(str3, ERR);
	ft_putstr_fd("\n", ERR);
	exit (retrn);
}
