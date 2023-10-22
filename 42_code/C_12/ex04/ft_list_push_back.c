/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:09:44 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/14 01:07:27 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*cur;

	cur = *begin_list;
	while (cur && cur->next)
		cur = cur->next;
	if (!cur)
		*begin_list = ft_create_elem(data);
	else
		cur->next = ft_create_elem(data);
}
