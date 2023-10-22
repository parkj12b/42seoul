/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:19:37 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 17:06:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_first(t_list **cur, t_list **next,
		t_list ***begin_list, void (*free_fct)(void *))
{
	free_fct((*cur)->data);
	free(*cur);
	*cur = *next;
	**begin_list = *cur;
	if (*cur != 0)
		*next = (*cur)->next;
}

void	swap_middle(t_list **prev, t_list **cur,
		t_list **next, void (*free_fct)(void *))
{
	(*prev)->next = *next;
	free_fct((*cur)->data);
	free(*cur);
	*cur = *next;
	if (*cur != 0)
		*next = (*cur)->next;
}

void	no_swap(t_list **prev, t_list **cur, t_list **next)
{
	*prev = *cur;
	*cur = *next;
	if (*next != 0)
		*next = (*next)->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()
		, void (*free_fct)(void *))
{
	t_list	*next;
	t_list	*prev;
	t_list	*cur;

	if (*begin_list == 0)
		return ;
	cur = *begin_list;
	prev = *begin_list;
	next = (*begin_list)->next;
	while (cur != 0)
	{
		if (cmp(cur->data, data_ref) == 0)
		{
			if (*begin_list == cur)
			{
				swap_first(&cur, &next, &begin_list, free_fct);
				prev = cur;
			}
			else
				swap_middle(&prev, &cur, &next, free_fct);
		}
		else
			no_swap(&prev, &cur, &next);
	}
}
