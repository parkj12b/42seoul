/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:43:54 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 17:01:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*cur;
	t_list	*prev;
	t_list	*to_add;

	to_add = ft_create_elem(data);
	prev = *begin_list;
	cur = *begin_list;
	while (cur && cmp(cur->data, to_add->data) < 0)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == *begin_list)
	{
		*begin_list = to_add;
		to_add->next = cur;
	}
	else
	{
		prev->next = to_add;
		to_add->next = cur;
	}
}
