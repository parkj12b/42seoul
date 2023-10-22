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

int	ft_realloc(t_vector *vec)
{
	char	*temp;

	vec->size *= 2;
	temp = malloc(sizeof(char) * (vec->size + 1));
	if (!temp)
	{
		free (vec->buffer);
		return (-1);
	}
	ft_strncpy(temp, vec->buffer, vec->idx);
	free(vec->buffer);
	vec->buffer = temp;
	return (0);
}

int	read_from_file_in_vector(int fd, t_vector *vec)
{
	int	r;

	vec->size = 2048;
	vec->idx = 0;
	vec->buffer = malloc(sizeof(char) * (vec->size + 1));
	if (!vec->buffer)
		return (0);
	r = read(fd, &vec->buffer[vec->idx++], 1);
	if (r < 0)
		return (free_and_return_zero(vec->buffer));
	while (r > 0)
	{
		r = read(fd, &vec->buffer[vec->idx], vec->size - vec->idx);
		vec->idx += r;
		if (vec->idx == vec->size)
			if (ft_realloc(vec) == -1)
				return (0);
	}
	if (vec->buffer[vec->idx - 1] != '\n')
		return (free_and_return_zero(vec->buffer));
	return (1);
}
