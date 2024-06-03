/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:11:19 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/05 16:54:30 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "parser.h"

int	ft_isspace(int c)
{
	if (c >= 9 && c <= 12)
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

int	is_str_limiter(const char *limiter, const char *str)
{
	int	limiter_len;
	int	str_len;

	limiter_len = ft_strlen(limiter);
	str_len = ft_strlen(str);
	if (limiter_len == str_len - 1
		&& ft_strncmp(limiter, str, limiter_len) == 0)
		return (1);
	return (0);
}

void	free_2d_pointer(void **pointer)
{
	int	i;

	i = -1;
	if (!pointer)
		return ;
	while (pointer[++i])
	{
		free(pointer[i]);
	}
	free(pointer);
}
