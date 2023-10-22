/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:28:37 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/24 17:45:05 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	calc_combi(int *a, int *b, int *c, char *arr)
{
	(*c)++;
	if (*b > 8)
	{
		(*a)++;
		*b = *a + 1;
		*c = *b + 1;
	}
	else if (*c > 9)
	{
		(*b)++;
		*c = *b + 1;
	}
	if (*a != 7 && *c < 10)
	{
		arr[0] = *a + '0';
		arr[1] = *b + '0';
		arr[2] = *c + '0';
		write(1, &arr[0], 5);
	}
}

void	ft_print_comb(void)
{
	char	arr[5];
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 1;
	c = 1;
	arr[3] = ',';
	arr[4] = ' ';
	while (a != 7)
		calc_combi(&a, &b, &c, arr);
	arr[0] = a + '0';
	arr[1] = b + '0';
	arr[2] = c + '0';
	write(1, &arr[0], 3);
}
