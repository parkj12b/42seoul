/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:13:04 by minsepar          #+#    #+#             */
/*   Updated: 2025/09/17 22:00:24 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int ret;

	if (!s)
		return ;
	ret = write(fd, s, ft_strlen(s));
	if (ret == -1)
		exit(1);
	ret = write(fd, "\n", 1);
	if (ret == -1)
		exit(1);
}
