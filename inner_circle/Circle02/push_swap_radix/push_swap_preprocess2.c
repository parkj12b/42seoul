/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_preprocess2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:21:23 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/03 14:23:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*normalize_list(t_index_node **list, int size)
{
	int				*int_list;
	int				i;

	int_list = (int *)malloc(sizeof(int) * size);
	if (!int_list)
		throw_error();
	i = -1;
	while (++i < size)
		list[i]->sorted_index = i;
	i = -1;
	while (++i < size)
		int_list[list[i]->original_index] = list[i]->sorted_index;
	return (int_list);
}

void	preprocess_normalization(t_stack *stack, int *order_list)
{
	t_stack_node	*cur;
	int				i;

	cur = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		cur->normalized_index = order_list[cur->index];
		cur = cur->next;
	}
}

void	set_original_index(t_stack *stack_copied)
{
	t_stack_node	*cur;
	int				i;

	i = -1;
	cur = stack_copied->head;
	while (++i < stack_copied->size)
	{
		cur->original_index = i;
		cur = cur->next;
	}
}

void	set_order_list(t_stack *sorted_stack, int *order_list)
{
	t_stack_node	*cur;
	int				i;

	i = -1;
	cur = sorted_stack->head;
	while (++i < sorted_stack->size)
	{
		order_list[i] = cur->index;
		cur = cur->next;
	}
}

void	preprocess_under_108(t_stack *stack)
{
	t_stack	*stack_copied;
	t_stack	stack_b;
	int		*order_list;

	stack_copied = copy_stack(stack);
	list_init(&stack_b, 'n');
	copy_index_to_norm_index(stack_copied);
	radix_base3(stack_copied, &stack_b, 3);
	radix_base4(&stack_b, stack_copied, 1);
	if (stack_b.size > 0)
		push_b_to_a(stack_copied, &stack_b);
	order_list = (int *)malloc(sizeof(int) * stack->size);
	if (!order_list)
		throw_error();
	set_order_list(stack_copied, order_list);
	preprocess_normalization(stack, order_list);
	free(order_list);
	free_list(stack_copied);
	free(stack_copied);
}
