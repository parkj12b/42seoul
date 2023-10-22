/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:28:48 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 20:56:34 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	free_all(t_char_buffer *root)
{
	t_char_buffer	*prev;

	while (root)
	{
		prev = root;
		root = root->next;
		free(prev);
	}
}

void	free_table_info(t_info *ti, char *buff_list)
{
	int	i;

	i = 0;
	while (i < ti->height)
	{
		if (ti->char_map[i])
			free(ti->char_map[i]);
		else
			break ;
		i++;
	}
	free(ti->char_map);
	free(buff_list);
}

void	free_int_map(t_info *ti)
{
	int	i;

	i = 0;
	while (i < ti->height)
	{
		free(ti->map[i]);
		i++;
	}
	free(ti->map);
}
