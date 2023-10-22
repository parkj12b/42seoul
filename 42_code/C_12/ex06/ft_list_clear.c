/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 03:28:50 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 14:20:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	while (begin_list && begin_list != 0)
	{
		next = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}
