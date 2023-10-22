/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:30:31 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 17:00:05 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

int	get_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

void	swap_data(int i, int size, t_list *begin_list)
{
	void	*temp;
	t_list	*second;
	int		counter;

	counter = 0;
	second = begin_list;
	while (i + counter < size - i - 1)
	{
		second = second->next;
		counter++;
	}
	temp = begin_list->data;
	begin_list->data = second->data;
	second->data = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	size;
	int	i;

	size = get_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		swap_data(i, size, begin_list);
		begin_list = begin_list->next;
		i++;
	}
}
