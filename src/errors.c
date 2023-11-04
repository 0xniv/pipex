/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:39:06 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 19:17:48 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	invalid_args(void)
{
	ft_putendl_fd("Invalid arguments: \n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
