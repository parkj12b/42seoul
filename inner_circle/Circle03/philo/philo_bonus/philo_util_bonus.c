/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:57:08 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 13:09:12 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_dead(t_common *common, int philo_num, char *message)
{
	t_parse_str	*parse_str;
	char		*temp;

	parse_str = &common->parse_str;
	parse_str->cursor = 0;
	parse_str->str[0] = 0;
	temp = ft_itoa(get_timestamp_ms(common));
	append_str(parse_str, temp);
	append_char(parse_str, ' ');
	free(temp);
	temp = ft_itoa(philo_num);
	append_str(parse_str, temp);
	append_char(parse_str, ' ');
	free(temp);
	append_str(parse_str, message);
	append_char(parse_str, '\n');
	write(1, parse_str->str, parse_str->cursor);
}

int	is_dead(t_common *common, t_philo *philo)
{
	size_t	time_diff;
	size_t	time_to_die_usec;

	sem_wait(philo->last_time_lock);
	time_diff = get_cur_time_us() - philo->last_eat_time;
	time_to_die_usec = common->time_to_die * 1000;
	if (time_diff >= time_to_die_usec)
	{
		sem_wait(common->print_lock);
		print_dead(common, philo->philo_num, "died");
		sem_post(philo->last_time_lock);
		return (TRUE);
	}
	sem_post(philo->last_time_lock);
	return (FALSE);
}

void	ft_msleep(int msec)
{
	size_t	start;
	size_t	cur;
	size_t	duration_usec;

	start = get_cur_time_us();
	cur = start;
	duration_usec = msec * 1000;
	while (cur - start < duration_usec)
	{
		cur = get_cur_time_us();
		if (duration_usec - (cur - start) > 1000)
		{
			usleep(500);
		}
	}
}
