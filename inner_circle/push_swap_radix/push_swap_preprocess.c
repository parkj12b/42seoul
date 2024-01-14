/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_preprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:19:55 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 22:23:02 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alist_to_nodelist_helper(char **parsed_string,
		t_index_node **list, int *size)
{
	int	i;

	i = -1;
	while (++i < *size)
	{
		list[i] = (t_index_node *)malloc(sizeof(t_index_node));
		if (!list[i])
			throw_error();
		list[i]->value = ft_safe_atoi(parsed_string[i]);
		list[i]->original_index = i;
		list[i]->sorted_index = 0;
	}
}

t_index_node	**alist_to_nodelist(char **argv, int *size)
{
	t_index_node	**list;
	char			**parsed_string;

	if (*size == 2)
		parsed_string = ft_split(argv[0], ' ');
	else
		parsed_string = argv;
	*size = count_words(parsed_string);
	list = (t_index_node **)ft_calloc(sizeof(t_index_node *), *size);
	if (!list)
		throw_error();
	alist_to_nodelist_helper(parsed_string, list, size);
	return (list);
}

void	swap_index_node_value(t_index_node **list, int i, int j)
{
	t_index_node	*node;

	if (i == j)
		return ;
	node = list[i];
	list[i] = list[j];
	list[j] = node;
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

void	quicksort_list(t_index_node **list, int low, int high)
{
	int	pivot;

	if (low >= high)
		return ;
	pivot = partition(list, low, high);
	quicksort_list(list, low, pivot - 1);
	quicksort_list(list, pivot + 1, high);
}
