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

char	*get_buff_list_from_vec(t_vector *vec)
{
	char	*ret;

	ret = malloc(sizeof(char) * (vec->idx + 1));
	ft_strncpy(ret, vec->buffer, vec->idx);
	return (ret);
}

int	process_map(int fd)
{
	char			*buff_list;
	t_info			ti;
	t_vector		vec;

	if (!read_from_file_in_vector(fd, &vec))
		return (0);
	buff_list = get_buff_list_from_vec(&vec);
	free(vec.buffer);
	if (!buff_list)
		return (0);
	init_info(&ti);
	if (!set_info(buff_list, &ti))
	{
		free_table_info(&ti, buff_list);
		return (0);
	}
	if (!solution(&ti))
	{
		free_table_info(&ti, buff_list);
		return (0);
	}
	free_table_info(&ti, buff_list);
	return (1);
}
