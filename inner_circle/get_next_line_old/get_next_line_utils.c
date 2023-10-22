/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:29:07 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/13 14:43:30 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void **mem1, void *mem2, void *mem3, void *mem4);

unsigned int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*malloc_str(t_dyn_char *dyn_str, size_t len)
{
	if (len == 0)
		len = 1024;
	dyn_str->str = (char *)malloc(len + 1);
	if (!dyn_str->str)
		return (0);
	dyn_str->i = 0;
	dyn_str->size = len;
	dyn_str->str[0] = 0;
	dyn_str->str[len] = 0;
	return (dyn_str->str);
}

void	*append(t_dyn_char *dyn_str, char *str, size_t start, size_t end)
{
	char		*temp;
	size_t		temp_i;
	size_t		multiplier;

	multiplier = 1;
	if (!str)
		return (0);
	temp_i = dyn_str->i;
	while (dyn_str->size * multiplier < dyn_str->i + (end - start))
		multiplier *= 2;
	temp = dyn_str->str;
	if (multiplier > 1)
		temp = (char *)malloc(dyn_str->size * multiplier + 1);
	dyn_str->size *= multiplier;
	if (!temp && multiplier > 1)
		return (ft_free((void **)&dyn_str->str, 0, 0, 0));
	while (temp_i-- > 0)
		temp[temp_i] = dyn_str->str[temp_i];
	while (start < end)
		temp[dyn_str->i++] = str[start++];
	if (multiplier > 1)
		free(dyn_str->str);
	dyn_str->str = temp;
	dyn_str->str[dyn_str->i] = 0;
	return (dyn_str->str);
}

void	*ft_free(void **zmem, void *mem2, void *mem3, void *mem4)
{
	free(*zmem);
	*zmem = 0;
	free(mem2);
	free(mem3);
	free(mem4);
	return (0);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *s_cpy;
	size_t	s_len;

    if (!s)
        return (0);
    while (*s && start > 0)
	{
		start--;
		s++;
	}
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
    s_cpy = (char *)malloc(len + 1);
    if (!s_cpy)
        return (0);
	i = 0;
    while (s[i] && i < len)
    {
        s_cpy[i] = s[i];
        i++;
    }
    s_cpy[i] = 0;
    return (s_cpy);
}
