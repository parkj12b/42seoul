/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:35:19 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/28 16:38:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_init;
	unsigned int	i;

	i = 0;
	dest_init = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && i < nb)
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_init);
}
