/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:11:13 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/14 01:10:53 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*cur;
	t_list	*next;
	t_list	*prev;

	cur = *begin_list;
	if (!cur)
		return ;
	next = cur->next;
	prev = 0;
	while (cur->next != 0)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		next = cur->next;
	}
	cur->next = prev;
	*begin_list = cur;
}
