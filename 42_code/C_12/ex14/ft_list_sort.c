/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:49:59 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 16:59:13 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap(t_list **prev, t_list **cur, t_list **next, t_list ***begin_list)
{
	if (*cur == **begin_list)
	{
		(*cur)->next = (*cur)->next->next;
		**begin_list = *next;
		(*next)->next = *cur;
		*cur = **begin_list;
		*next = (*cur)->next;
	}
	else
	{
		(*cur)->next = (*cur)->next->next;
		(*prev)->next = *next;
		(*next)->next = *cur;
		*cur = (*prev)->next;
		*next = (*prev)->next->next;
	}
}

int	get_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != 0)
	{
		begin_list = (begin_list)->next;
		i++;
	}
	return (i);
}

void	sort(t_ptr *ptr, t_list **begin_list, int (*cmp)())
{
	int	i;
	int	j;

	i = get_size(*begin_list);
	j = 0;
	while (j < i)
	{
		ptr->prev = *begin_list;
		ptr->cur = *begin_list;
		ptr->next = ptr->cur->next;
		while (j < i - 1)
		{
			if (cmp(ptr->cur->data, ptr->next->data) > 0)
				swap(&ptr->prev, &ptr->cur, &ptr->next, &begin_list);
			j++;
			ptr->prev = ptr->cur;
			ptr->cur = ptr->next;
			if (ptr->next)
				ptr->next = ptr->next->next;
		}
		i--;
		j = 0;
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_ptr	ptr;
	int		i;
	int		j;

	j = 0;
	i = get_size(*begin_list);
	if (*begin_list == 0 || (*begin_list)->next == 0)
		return ;
	ptr.prev = *begin_list;
	ptr.cur = *begin_list;
	ptr.next = ptr.cur->next;
	sort(&ptr, begin_list, cmp);
}
