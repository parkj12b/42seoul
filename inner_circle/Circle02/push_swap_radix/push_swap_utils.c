/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:11:12 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 22:16:26 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_safe_atoi_helper(const char **str, int *flag, long *num)
{
	while (**str && **str >= '0' && **str <= '9' && *num <= INT32_MAX)
	{
		*flag = 1;
		*num *= 10;
		*num += **str - '0';
		*str = *str + 1;
	}
}

int	ft_safe_atoi(const char *str)
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
	ft_safe_atoi_helper(&str, &flag, &num);
	num *= sign;
	if (flag == 0 || *str || num > INT32_MAX || num < INT32_MIN)
		throw_error();
	return (num);
}

int	count_words(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
