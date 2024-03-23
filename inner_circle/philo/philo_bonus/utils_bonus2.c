/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:19:15 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 23:58:27 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	while (src[i] && i + dst_len + 1 < dstsize)
	{
			dst[dst_len + i] = src[i];
			i++;
	}
	if (dst_len + i < dstsize)
			dst[dst_len + i] = 0;
	else
		return (ft_strlen(src) + dstsize);
	return (dst_len + ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
