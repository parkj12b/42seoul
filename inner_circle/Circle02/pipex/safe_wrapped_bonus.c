/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_wrapped_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:03:59 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/04 19:06:37 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*safe_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		shell_error("pipex");
	return (mem);
}

void	*safe_calloc(size_t size, size_t num)
{
	void	*mem;

	mem = ft_calloc(size, num);
	if (!mem)
		shell_error("pipex");
	return (mem);
}
