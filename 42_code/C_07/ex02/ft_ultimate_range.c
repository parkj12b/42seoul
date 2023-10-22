/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:16:05 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/03 22:29:43 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*malloc_var;

	i = 0;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	malloc_var = (int *)malloc(sizeof(int) * ((unsigned int) max - min));
	if (malloc_var == 0)
		return (-1);
	while (min + i < max)
	{
		malloc_var[i] = min + i;
		i++;
	}
	*range = malloc_var;
	return (max - min);
}
