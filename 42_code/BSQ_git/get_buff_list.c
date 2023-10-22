/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buff_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:28:34 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 20:56:36 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	get_size(t_char_buffer *root)
{
	int	size;

	size = 0;
	while (root)
	{
		size += root->len;
		root = root->next;
	}
	return (size);
}

char	*get_buff_list(t_char_buffer *head)
{
	unsigned int	buff_list_size;
	char			*buff_list;
	int				i;
	int				idx;

	buff_list_size = get_size(head);
	buff_list = malloc(sizeof(char) * (buff_list_size + 1));
	if (!buff_list)
		return (0);
	idx = 0;
	while (head)
	{
		i = 0;
		while (i < head->len)
			buff_list[idx++] = head->buffer[i++];
		head = head->next;
	}
	buff_list[idx] = 0;
	return (buff_list);
}
