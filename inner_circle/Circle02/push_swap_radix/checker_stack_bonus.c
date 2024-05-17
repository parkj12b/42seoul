/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:46:00 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/01 21:04:28 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list_node	*create_node(int num)
{
	t_list_node	*node;

	node = (t_list_node *)malloc(sizeof(t_list_node));
	if (!node)
		return (0);
	node->index = num;
	node->cur_digit = num;
	node->next = 0;
	node->prev = 0;
	return (node);
}

int	enqueue(t_list_node *new_node, t_list *list)
{
	int	index;

	index = 0;
	if (!new_node)
		return (1);
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
	return (0);
}

t_list_node	*dequeue(t_list *list)
{
	t_list_node	*head;

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

int	rotate_stack(t_list *list)
{
	if (list->size == 0)
		return (1);
	list->head = list->head->next;
	list->last = list->last->next;
	return (0);
}

int	reverse_rotate_stack(t_list *list)
{
	if (list->size == 0)
		return (1);
	list->head = list->head->prev;
	list->last = list->last->prev;
	return (0);
}
