/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:22 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 17:07:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	cur = *begin_list1;
	if (cur == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = begin_list2;
}
