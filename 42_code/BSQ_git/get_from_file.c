/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:38:41 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 20:56:39 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	append_char(t_linked_list *list, char buff)
{
	t_char_buffer	*last;

	last = list->tail;
	if (last->len == 2048)
	{
		last->next = get_new_buffer();
		last = last->next;
		list->tail = last;
	}
	last->buffer[last->len++] = buff;
}

t_char_buffer	*get_new_buffer(void)
{
	t_char_buffer	*ret;

	ret = (t_char_buffer *)malloc(sizeof(t_char_buffer));
	if (!ret)
		return (0);
	ret->len = 0;
	ret->next = 0;
	return (ret);
}

int	read_from_file(int fd, t_linked_list *list)
{
	char			buff;
	int				r;

	r = read(fd, &buff, 1);
	if (r < 0)
		return (0);
	list->head = get_new_buffer();
	list->tail = list->head;
	if (!list->head)
		return (0);
	while (r > 0)
	{
		append_char(list, buff);
		r = read(fd, &buff, 1);
	}
	if (buff != '\n')
	{
		free_all(list->head);
		return (0);
	}
	return (1);
}
