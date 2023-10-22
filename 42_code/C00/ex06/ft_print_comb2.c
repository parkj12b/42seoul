/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:50:59 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/25 15:09:03 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_to_arr(int *a, int *b, char *arr)
{
	if (*a < 10)
	{
		arr[0] = '0';
		arr[1] = *a + '0';
	}
	else
	{
		arr[0] = *a / 10 + '0';
		arr[1] = *a % 10 + '0';
	}
	if (*b < 10)
	{
		arr[3] = '0';
		arr[4] = *b + '0';
	}
	else
	{
		arr[3] = *b / 10 + '0';
		arr[4] = (*b) % 10 + '0';
	}
}

void	ft_print_comb_inner(int *a, int *b, char *arr)
{
	(*b)++;
	if (*b > 99)
	{
		(*a)++;
		*b = *a + 1;
	}
	if (*b < 100 && *a < 98)
	{
		write_to_arr(a, b, arr);
		write(1, arr, 7);
	}
}

void	ft_print_comb2(void)
{
	char	arr[7];
	int		a;
	int		b;

	a = 0;
	b = 0;
	arr[5] = ',';
	arr[6] = ' ';
	arr[2] = ' ';
	arr[0] = '0';
	arr[3] = '0';
	while (a < 98)
	{
		ft_print_comb_inner(&a, &b, arr);
	}
	write_to_arr(&a, &b, arr);
	write(1, arr, 5);
}
