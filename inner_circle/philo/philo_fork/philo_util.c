/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:53:12 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/12 01:51:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
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
	return ((int)(num * sign));
}

size_t	get_current_time_usec()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	elapsed;
	size_t	start;
	size_t	remaining;
	size_t	usec;

	start = get_current_time_usec();
	elapsed = get_current_time_usec() - start;
	usec = milliseconds * 1000;
	remaining = usec - elapsed;
	while (elapsed < usec)
	{
		if (remaining > 1000)
			usleep(remaining / 2);
		elapsed = get_current_time_usec() - start;
		usec = milliseconds * 1000;
		remaining = usec - elapsed;
	}
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	get_timestamp(t_args *t_args)
{
	struct timeval	now;
	size_t			time;

	gettimeofday(&now, NULL);
	time = get_current_time()
		- ((t_args->start_time.tv_sec) * 1000
			+ (t_args->start_time.tv_usec) / 1000);
	return (time);
}
