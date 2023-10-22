/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:55:16 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/28 22:41:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	custom_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = custom_strlen(dest);
	src_len = custom_strlen(src);
	i = 0;
	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (i + 1 < size && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	if (i < size)
		*dest = '\0';
	if (size < dest_len)
		return (size + src_len);
	return (dest_len + src_len);
}
