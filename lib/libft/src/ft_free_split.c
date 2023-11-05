/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:10:38 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 21:23:06 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}
