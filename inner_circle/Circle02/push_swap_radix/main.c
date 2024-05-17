/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:07:38 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/03 14:38:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_index_node **sorted_list, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (sorted_list[i]->value == sorted_list[i - 1]->value)
			throw_error();
	}
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

void	list_init(t_stack *list, char type)
{
	list->size = 0;
	list->head = 0;
	list->last = 0;
	list->list_type = type;
}

int	main(int size, char **argv)
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_index_node	**sorted_list;
	int				*normalized_list;

	if (size <= 1)
		return (0);
	sorted_list = alist_to_nodelist(&argv[1], &size);
	quicksort_list(sorted_list, 0, size - 1);
	check_duplicate(sorted_list, size);
	normalized_list = normalize_list(sorted_list, size);
	free_node_list(sorted_list, size);
	check_sorted(normalized_list, size);
	list_init(&stack_a, 'a');
	list_init(&stack_b, 'b');
	stack_a_init(&stack_a, normalized_list, size);
	sort_stack(&stack_a, &stack_b);
	free_list(&stack_a);
}
