/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:53:17 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/01 21:04:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a_and_b(t_list *stack_a, t_list *stack_b)
{
	if (swap_top(stack_a) || swap_top(stack_b))
	{
		free_list(stack_a);
		free_list(stack_b);
		throw_error(0, 0, 0, 0);
	}
}

void	rotate_a_and_b(t_list *stack_a, t_list *stack_b)
{
	if (rotate_stack(stack_a) || rotate_stack(stack_b))
	{
		free_list(stack_a);
		free_list(stack_b);
		throw_error(0, 0, 0, 0);
	}
}

void	reverse_rotate_a_and_b(t_list *stack_a, t_list *stack_b)
{
	if (reverse_rotate_stack(stack_a) || reverse_rotate_stack(stack_b))
		throw_error(0, 0, 0, 0);
}

void	free_list(t_list *list)
{
	t_list_node	*cur;

	if (!list || !list->head)
		return ;
	cur = dequeue(list);
	while (cur)
	{
		free(cur);
		cur = dequeue(list);
	}
}
