/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:29:25 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 00:09:24 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * does not guard int max or overflow
 * return 0 on success, 1 on fail
*/
int	ft_atoi_num_only(const char *str, int *return_num)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	*return_num = (int)(num * sign);
	if (*str == '\0')
		return (SUCCESS);
	return (ERROR);
}

void	*nul_guard(void *mem)
{
	if (mem == NULL)
	{
		print_error(ERROR);
		exit(ERROR);
	}
	return (mem);
}

size_t	get_cur_time_us(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000000 + cur.tv_usec);
}

size_t	get_timestamp_ms(t_common *common)
{
	size_t	time_diff;

	time_diff = get_cur_time_us() - common->start_time;
	return (time_diff / 1000);
}

void	printf_philo(t_common *common, int philo_num, char *message)
{
	sem_wait(common->print_lock);
	printf("%zu %d %s\n", get_timestamp_ms(common), philo_num, message);
	sem_post(common->print_lock);
}
