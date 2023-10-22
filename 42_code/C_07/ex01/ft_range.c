/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:54:12 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/04 10:14:06 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr_int;
	unsigned int	i;

	i = 0;
	if (max <= min)
	{
		return (0);
	}
	arr_int = (int *)malloc(sizeof(int) * ((unsigned int)(max - min)));
	if (arr_int == 0)
	{
		return (0);
	}
	while (min < max)
	{
		arr_int[i] = min;
		min++;
		i++;
	}
	return (arr_int);
}
