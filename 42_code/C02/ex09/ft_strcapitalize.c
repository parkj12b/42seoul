/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 20:12:32 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/27 10:41:48 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	to_lowercase(char *str)
{
	int	diff;

	diff = 'a' - 'A';
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += diff;
		str++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		diff;
	char	*start;

	start = str;
	diff = 'a' - 'A';
	to_lowercase(str);
	if (*str >= 'a' && *str <= 'z')
		*str -= diff;
	str++;
	while (*str != '\0')
	{
		if (*(str) >= 'a' && *(str) <= 'z'
			&& ((*(str - 1) > '9' && *(str - 1) < 'A') || *(str - 1) < '0'
				|| (*(str - 1) > 'Z' && *(str - 1) < 'a')
				|| *(str - 1) > 'z'))
		{
			*str -= diff;
		}
		str++;
	}
	return (start);
}
