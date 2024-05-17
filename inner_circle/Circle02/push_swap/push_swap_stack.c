/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:12:39 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/03 19:44:47 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_node(int num)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (0);
	node->index = num;
	node->cur_digit = num;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	enqueue(t_stack_node *new_node, t_stack *list)
{
	int	index;

	index = 0;
	if (!new_node)
		return ;
	if (!list->head)
	{
		list->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		list->last = new_node;
	}
	else
	{
		new_node->prev = list->last;
		list->head->prev = new_node;
		new_node->next = list->head;
		list->head = new_node;
		list->last->next = list->head;
	}
	list->size++;
}

t_stack_node	*dequeue(t_stack *list)
{
	t_stack_node	*head;

	head = list->head;
	if (!list || !list->head)
		return (0);
	else if (list->size == 1)
	{
		list->last = 0;
		list->head = 0;
	}
	else
	{
		list->head = head->next;
		list->head->prev = head->prev;
		list->last->next = list->head;
	}
	list->size--;
	return (head);
}

void	rotate_stack(t_stack *list)
{
	list->head = list->head->next;
	list->last = list->last->next;
	if (list->list_type == 'a')
		write(1, "ra\n", 3);
	else if (list->list_type == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate_stack(t_stack *list)
{
	list->head = list->head->prev;
	list->last = list->last->prev;
	if (list->list_type == 'a')
		write(1, "rra\n", 4);
	else if (list->list_type == 'b')
		write(1, "rrb\n", 4);
}
