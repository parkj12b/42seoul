/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:29:34 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 22:23:58 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_base4_helper(t_stack *s_from, t_stack *s_to, t_stack_node *cur)
{
	cur = s_from->head;
	if (s_from->head->normalized_index % 4 == 0)
	{
		push_stack(s_from, s_to);
		cur->normalized_index /= 4;
	}
	else if (s_from->head->normalized_index % 4 == 1)
	{
		push_stack(s_from, s_to);
		rotate_stack(s_to);
		cur->normalized_index /= 4;
	}
	else if (s_from->head->normalized_index % 4 == 2)
		rotate_stack(s_from);
	else
		rotate_stack(s_from);
}

void	radix_base4(t_stack *s_from, t_stack *s_to, int num_op)
{
	int				size;
	t_stack_node	*cur;

	cur = 0;
	if (num_op <= 0)
		return ;
	size = s_from->size;
	while (size-- > 0)
		radix_base4_helper(s_from, s_to, cur);
	size = s_from->size;
	while (size-- > 0)
	{
		cur = s_from->head;
		if (s_from->head->normalized_index % 4 == 2)
			push_stack(s_from, s_to);
		else
		{
			push_stack(s_from, s_to);
			rotate_stack(s_to);
		}
		cur->normalized_index /= 4;
	}
	num_op--;
	radix_base4(s_to, s_from, num_op);
}

void	sort_under_108(t_stack *stack_a, t_stack *stack_b)
{
	preprocess_under_108(stack_a);
	radix_base3(stack_a, stack_b, 3);
	radix_base4(stack_b, stack_a, 1);
}

void	sort_normal(t_stack *stack_a, t_stack *stack_b)
{
	int	num_op;

	num_op = num_operation(stack_a->size);
	preprocess_radix_sort_base4(stack_a);
	radix_base4(stack_a, stack_b, num_op);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 6)
		mini_sort(stack_a, stack_b);
	else if (stack_a->size < 108 && stack_a->size >= 81)
		sort_under_108(stack_a, stack_b);
	else
		sort_normal(stack_a, stack_b);
	if (stack_b->size > 0)
		push_b_to_a(stack_a, stack_b);
}
