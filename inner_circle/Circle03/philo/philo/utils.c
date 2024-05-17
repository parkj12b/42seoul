/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:29:25 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 13:57:53 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

/**
 * sets status code on error, else, same as malloc
 * takes t_common struct for status code
*/
void	*safe_malloc(t_common *common, size_t size)
{
	void	*return_mem;

	return_mem = malloc(size);
	if (return_mem == NULL)
	{
		common->status_code = ERROR;
		return (NULL);
	}
	return (return_mem);
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
	pthread_mutex_lock(&common->print_mutex);
	if (is_finished(common) == TRUE)
	{
		pthread_mutex_unlock(&common->print_mutex);
		return ;
	}
	printf("%zu %d %s\n", get_timestamp_ms(common), philo_num, message);
	pthread_mutex_unlock(&common->print_mutex);
}
