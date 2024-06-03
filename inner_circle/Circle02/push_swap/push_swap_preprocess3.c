/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_preprocess3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:26:08 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 22:20:47 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_index_to_norm_index(t_stack *stack_copied)
{
	int				i;
	t_stack_node	*cur;

	i = -1;
	cur = stack_copied->head;
	while (++i < stack_copied->size)
	{
		cur->normalized_index = cur->index;
		cur = cur->next;
	}
}

void	preprocess_radix_sort_base4(t_stack *stack)
{
	t_stack	*stack_copied;
	t_stack	stack_b;
	int		*order_list;
	int		num_op;

	num_op = num_operation(stack->size);
	stack_copied = copy_stack(stack);
	list_init(&stack_b, 'n');
	copy_index_to_norm_index(stack_copied);
	radix_base4(stack_copied, &stack_b, num_op);
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
