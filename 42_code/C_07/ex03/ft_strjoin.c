/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:50:19 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/04 10:14:43 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	final_join(char	*join_str, char **strs, int size, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			join_str[k++] = strs[i][j++];
		}
		j = 0;
		while (i != size - 1 && sep[j] != '\0')
		{
			join_str[k++] = sep[j++];
		}
		i++;
	}
	join_str[k] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat_str;
	int		total_len;
	int		i;

	if (size == 0)
	{
		cat_str = (char *) malloc(sizeof(char));
		*cat_str = 0;
		return (cat_str);
	}
	total_len = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	cat_str = (char *)malloc(sizeof(char) * (total_len + 1));
	final_join(cat_str, strs, size, sep);
	return (cat_str);
}
