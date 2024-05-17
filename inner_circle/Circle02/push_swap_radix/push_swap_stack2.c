/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:15:31 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 22:20:56 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*second;

	head = stack->head;
	second = stack->head->next;
	stack->head = second;
	second->next = head;
	second->prev = head;
	head->next = second;
	head->prev = second;
	stack->last = head;
}

void	print_swap(t_stack *stack)
{
	if (stack->list_type == 'a')
		write(1, "sa\n", 3);
	else if (stack->list_type == 'b')
		write(1, "sb\n", 3);
}

void	swap_top(t_stack *list)
{
	t_stack_node	*head;
	t_stack_node	*second;

	if (list->size < 2)
		return ;
	head = list->head;
	second = list->head->next;
	if (list->size == 2)
		swap_top_two(list);
	else
	{
		head->next = second->next;
		second->prev = head->prev;
		second->next->prev = head;
		head->prev = second;
		second->next = head;
		list->head = second;
		list->last->next = list->head;
	}
	print_swap(list);
}

void	push_stack(t_stack *list_from, t_stack *list_to)
{
	enqueue(dequeue(list_from), list_to);
	if (list_to->list_type == 'a')
		write(1, "pa\n", 3);
	else if (list_to->list_type == 'b')
		write(1, "pb\n", 3);
}

void	stack_a_init(t_stack *stack_a, int *normalized_list, int size)
{
	t_stack_node	*new_node;

	while (size-- > 0)
	{
		new_node = create_node(normalized_list[size]);
		if (!new_node)
		{
			free_list(stack_a);
			throw_error();
		}
		enqueue(new_node, stack_a);
	}
	free(normalized_list);
}
