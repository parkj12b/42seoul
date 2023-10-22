/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:29:07 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/11 20:56:46 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!dyn_str)
		return (0);
	dyn_str->i = 0;
	dyn_str->size = len;
	dyn_str->str[0] = 0;
	return (dyn_str->str);
}

int	append(t_dyn_char *dyn_str, char *str, int start, int end)
{
	size_t	len;
	char	*temp;
	int		temp_i;

	if (!str)
		return (1);
	len = ft_strlen(str);
	temp_i = dyn_str->i;
	while (dyn_str->size < dyn_str->i + len)
		dyn_str->size *= 2;
	temp = (char *)malloc(dyn_str->size);
	if (!temp)
	{
		free(dyn_str->str);
		return (1);
	}
	while (temp_i-- > 0)
		temp[temp_i] = dyn_str->str[temp_i];
	while (start < end)
		temp[dyn_str->i++] = str[start++];
	free(dyn_str->str);
	dyn_str->str = temp;
	dyn_str->str[dyn_str->i] = 0;
	return (0);
}

static char *ft_substr_helper(void)
{
    char    *s_cpy;

    s_cpy = (char *)malloc(1);
    if (!s_cpy)
        return (0);
    s_cpy[0] = 0;
    return (s_cpy);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *s_cpy;

    i = 0;
    if (!s)
        return (0);
    if (start >= ft_strlen(s))
        return (ft_substr_helper());
    if (ft_strlen(s) - start < len)
        len = ft_strlen(s) - start;
    s_cpy = (char *)malloc(len + 1);
    if (!s_cpy)
        return (s_cpy);
    while (s[start + i] && i < len)
    {
        s_cpy[i] = s[start + i];
        i++;
    }
    s_cpy[i] = 0;
    return (s_cpy);
}
