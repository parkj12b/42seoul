/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:59:40 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 22:39:30 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap(t_list **prev, t_list **cur)
{
	*prev = *cur;
	*cur = (*cur)->next;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;

	prev = *begin_list1;
	cur = *begin_list1;
	while (begin_list2)
	{
		next = begin_list2->next;
		while (cur && cmp(begin_list2->data, cur->data) > 0)
			swap(&prev, &cur);
		if (*begin_list1 == cur)
		{
			*begin_list1 = begin_list2;
			begin_list2->next = cur;
		}
		else
		{
			prev->next = begin_list2;
			begin_list2->next = cur;
		}
		prev = begin_list2;
		begin_list2 = next;
	}
}
