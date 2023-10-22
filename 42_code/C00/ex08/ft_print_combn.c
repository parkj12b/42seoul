/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:34:29 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/26 12:12:58 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	last_num(char *a, int len)
{
	int	num;
	int	i;

	i = 1;
	num = 9;
	while (i <= len)
	{
		if (*(a + len - i) == num + '0')
		{
			i++;
			num--;
		}
		else
		{
			return (0);
		}	
	}
	return (1);
}

void	combination(int depth, int index, char *arr, int n)
{
	int	i;

	i = index;
	if (depth == n)
	{
		write(1, arr, n);
		if (!last_num(arr, n))
			write(1, ", ", 2);
		return ;
	}
	while (i < 10)
	{
		arr[depth] = i + '0';
		combination (depth + 1, i + 1, arr, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	combination(0, 0, arr, n);
}
