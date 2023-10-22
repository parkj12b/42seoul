/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:23:15 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 20:56:43 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	process_map(int fd)
{
	t_linked_list	list;
	char			*buff_list;
	t_info			ti;

	if (!read_from_file(fd, &list))
		return (0);
	buff_list = get_buff_list(list.head);
	free_all(list.head);
	if (!buff_list)
		return (0);
	init_info(&ti);
	if (!set_info(buff_list, &ti))
	{
		free_table_info(&ti, buff_list);
		return (0);
	}
	solution(&ti);
	free_table_info(&ti, buff_list);
	return (1);
}
