/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:27:18 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/03 14:23:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_base3(t_stack *s_from, t_stack *s_to, int num_op)
{
	int				size;
	t_stack_node	*cur;

	if (num_op <= 0)
		return ;
	size = s_from->size;
	while (size-- > 0)
	{
		cur = s_from->head;
		if (s_from->head->normalized_index % 3 == 0)
			push_stack(s_from, s_to);
		else if (s_from->head->normalized_index % 3 == 1)
		{
			push_stack(s_from, s_to);
			rotate_stack(s_to);
		}
		else
			rotate_stack(s_from);
		cur->normalized_index /= 3;
	}
	num_op--;
	while (s_from->head)
		push_stack(s_from, s_to);
	radix_base3(s_to, s_from, num_op);
}

int	num_operation(int size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		size /= 4;
		i++;
	}
	return (i);
}

void	three_sort_a(t_stack *stack_a)
{
	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->head->index > stack_a->head->next->index)
			return (swap_top(stack_a));
	}
	else
	{
		if (!is_increasing(stack_a))
			swap_top(stack_a);
		if (stack_a->last->index < stack_a->head->next->index)
			reverse_rotate_stack(stack_a);
		else if (stack_a->head->index > stack_a->head->next->index)
			rotate_stack(stack_a);
	}
}

void	three_sort_b(t_stack *stack_b)
{
	if (stack_b->size == 1)
		return ;
	else if (stack_b->size == 2)
	{
		if (stack_b->head->index < stack_b->head->next->index)
			return (swap_top(stack_b));
	}
	else
	{
		if (is_increasing(stack_b))
			swap_top(stack_b);
		if (stack_b->head->next->index > stack_b->head->index)
			rotate_stack(stack_b);
		else if (stack_b->last->index > stack_b->head->next->index)
			reverse_rotate_stack(stack_b);
	}
}

void	mini_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;

	mid = stack_a->size / 2;
	if (stack_a->size <= 3)
		return (three_sort_a(stack_a));
	while (stack_b->size + 1 < stack_a->size)
	{
		if (stack_a->head->index < mid)
			push_stack(stack_a, stack_b);
		else
			rotate_stack(stack_a);
	}
	three_sort_a(stack_a);
	three_sort_b(stack_b);
}
