/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 20:03:03 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/25 20:11:54 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		diff;
	char	*start;

	start = str;
	diff = 'a' - 'A';
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += diff;
		str++;
	}
	return (start);
}
