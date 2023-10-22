/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:51:06 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/04 19:17:29 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != c && charset[i] != '\0')
		i++;
	if (charset[i] != '\0' || c == '\0')
		return (1);
	return (0);
}

int	get_num_words(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		while (is_separator(*str, charset))
			str++;
		if (!is_separator(*str, charset))
		{
			i++;
			while (*str != '\0' && !is_separator(*str, charset))
				str++;
		}
	}
	return (i);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str != '\0' && !is_separator(str[i], charset))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**return_ptr;
	int		i;

	i = 0;
	size = get_num_words(str, charset);
	return_ptr = (char **)malloc(sizeof(char *) * (size + 1));
	while (*str != '\0')
	{
		if (!is_separator(*str, charset))
		{
			size = ft_strlen(str, charset);
			return_ptr[i] = (char *)malloc(sizeof(char) * (size + 1));
			ft_strncpy(return_ptr[i], str, size);
			i++;
		}
		while (*str != '\0' && !is_separator(*str, charset))
			str++;
		while (*str != '\0' && is_separator(*str, charset))
			str++;
	}
	return_ptr[i] = 0;
	return (return_ptr);
}
