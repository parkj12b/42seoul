/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:47:38 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/01 21:13:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	stack_a_init(t_list *stack_a, int *normalized_list, int size)
{
	t_list_node	*new_node;

	while (size-- > 0)
	{
		new_node = create_node(normalized_list[size]);
		if (!new_node)
		{
			free_list(stack_a);
			throw_error(0, 0, normalized_list, 0);
		}
		enqueue(new_node, stack_a);
	}
	free(normalized_list);
}

void	list_init(t_list *list)
{
	list->size = 0;
	list->head = 0;
	list->last = 0;
}

void	swap_top_two(t_list *stack)
{
	t_list_node	*head;
	t_list_node	*second;

	head = stack->head;
	second = stack->head->next;
	stack->head = second;
	second->next = head;
	second->prev = head;
	head->next = second;
	head->prev = second;
	stack->last = head;
}

int	swap_top(t_list *list)
{
	t_list_node	*head;
	t_list_node	*second;

	if (list->size < 2)
		return (1);
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
	return (0);
}

void	push_stack(t_list *list_from, t_list *list_to)
{
	t_list_node	*temp;

	temp = dequeue(list_from);
	if (!temp)
	{
		free_list(list_from);
		free_list(list_to);
		throw_error(0, 0, 0, 0);
	}
	enqueue(temp, list_to);
}
