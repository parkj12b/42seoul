/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:22:16 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/03 19:46:29 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *list)
{
	t_stack_node	*cur;

	if (!list || !list->head)
		return ;
	cur = dequeue(list);
	while (cur)
	{
		free(cur);
		cur = dequeue(list);
	}
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack			*copy_stack;
	t_stack_node	*cur;
	int				i;

	copy_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!copy_stack)
		throw_error();
	list_init(copy_stack, 'n');
	cur = stack->last;
	i = -1;
	while (++i < stack->size)
	{
		enqueue(create_node(cur->index), copy_stack);
		cur = cur->prev;
	}
	return (copy_stack);
}

int	is_increasing(t_stack *stack)
{
	t_stack_node	*cur;
	int				i;
	int				increasing_num;

	cur = stack->head;
	i = -1;
	increasing_num = 0;
	while (++i < 4 && increasing_num < 2)
	{
		if (cur->index < cur->next->index)
			increasing_num++;
		else
			increasing_num = 0;
		cur = cur->next;
	}
	if (increasing_num == 2)
		return (1);
	else
		return (0);
}

void	free_node_list(t_index_node **sorted_list, int size)
{
	while (--size >= 0)
		free(sorted_list[size]);
	free(sorted_list);
}
