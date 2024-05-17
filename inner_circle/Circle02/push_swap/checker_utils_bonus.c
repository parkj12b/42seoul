/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:44:52 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/09 20:22:04 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_2d_free(void **mem, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(mem[i]);
	}
	free(mem);
}

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	count_words(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	ft_atoi_helper(const char **str, int *flag, long *num)
{
	while (**str && **str >= '0' && **str <= '9' && *num <= INT_MAX)
	{
		*flag = 1;
		*num *= 10;
		*num += **str - '0';
		*str = *str + 1;
	}
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		flag;
	long	num;

	num = 0;
	sign = 1;
	flag = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ft_atoi_helper(&str, &flag, &num);
	num *= sign;
	if (flag == 0 || *str || num > INT_MAX || num < INT_MIN)
		throw_error();
	return (num);
}
