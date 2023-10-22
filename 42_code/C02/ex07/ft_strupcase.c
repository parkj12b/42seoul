/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:45:00 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/25 20:01:12 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*start;
	int		diff;

	diff = 'a' - 'A';
	start = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= diff;
		str++;
	}
	return (start);
}
