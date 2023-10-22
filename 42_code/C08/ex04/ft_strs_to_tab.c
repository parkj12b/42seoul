/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:25:55 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/05 13:49:35 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_strcpy(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*return_ptr;
	int					i;

	i = 0;
	return_ptr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (return_ptr == 0)
	{
		return_ptr = 0;
		return (return_ptr);
	}
	while (ac > 0)
	{
		return_ptr[i].size = ft_strlen(av[i]);
		return_ptr[i].str = av[i];
		return_ptr[i].copy = (char *)malloc(sizeof(char)
				* (return_ptr[i].size + 1));
		ft_strcpy(return_ptr[i].copy, av[i]);
		ac--;
		i++;
	}
	return_ptr[i].str = 0;
	return (return_ptr);
}
