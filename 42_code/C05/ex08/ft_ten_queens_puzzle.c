/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:16:38 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/30 18:31:18 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_diagonal(char *arr, int depth, int i)
{
	int	j;

	j = 1;
	depth--;
	while (depth >= 0)
	{
		if ((i - j >= 0 && arr[depth] - '0' == i - j)
			|| (i + j < 10 && arr[depth] - '0' == i + j))
			return (0);
		j++;
		depth--;
	}
	return (1);
}

int	ten_queen_recursion(char *arr, int *occupied, int depth, int n)
{
	int	i;
	int	num_execution;

	i = 0;
	num_execution = 0;
	if (depth == n)
	{
		write(1, arr, 11);
		return (1);
	}
	while (i < 10)
	{
		if (!occupied[i] && check_diagonal(arr, depth, i))
		{
			occupied[i] = 1;
			arr[depth] = i + '0';
			num_execution += ten_queen_recursion(arr, occupied, depth + 1, n);
			occupied[i] = 0;
			arr[depth] = 'e';
		}
		i++;
	}
	return (num_execution);
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[11];
	int		occupied[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i] = 'e';
		occupied[i] = 0;
		i++;
	}
	arr[10] = '\n';
	i = ten_queen_recursion(arr, occupied, 0, 10);
	return (i);
}
