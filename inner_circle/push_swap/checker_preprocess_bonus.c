/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_preprocess_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:48:37 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/01 21:13:24 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_index_node_value(t_index_node **list, int i, int j)
{
	t_index_node	*node;

	if (i == j)
		return ;
	node = list[i];
	list[i] = list[j];
	list[j] = node;
}

int	check_sorted(int *normalized_list, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (normalized_list[i] != i)
			return (0);
	}
	free(normalized_list);
	exit(0);
}

void	free_node_list(t_index_node **sorted_list, int size)
{
	while (--size >= 0)
		free(sorted_list[size]);
	free(sorted_list);
}

void	quicksort_list(t_index_node **list, int low, int high)
{
	int	pivot;

	if (low >= high)
		return ;
	pivot = partition(list, low, high);
	quicksort_list(list, low, pivot - 1);
	quicksort_list(list, pivot + 1, high);
}

int	partition(t_index_node **list, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = list[low]->value;
	i = low + 1;
	j = high;
	while (i <= j)
	{
		while (i <= high && list[i]->value <= pivot)
			i++;
		while (j > low && list[j]->value >= pivot)
			j--;
		if (i > j)
			swap_index_node_value(list, low, j);
		else
			swap_index_node_value(list, i, j);
	}
	return (j);
}
