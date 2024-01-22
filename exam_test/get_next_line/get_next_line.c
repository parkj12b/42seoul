/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:53:19 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/16 20:38:02 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*init_t_gnl()
{
	t_gnl	*gnl;

	gnl = malloc(sizeof(t_gnl));
	gnl->str = malloc(BUFFER_SIZE + 1);
	if (!gnl->str)
		return (0);
	gnl->str[BUFFER_SIZE] = 0;
	gnl->malloc_size = BUFFER_SIZE;
	gnl->str_size = 0;
	gnl->index = 0;
	return (gnl);
}

int	check_size(t_gnl *t_gnl)
{
	char	*tmp_str;
	size_t	i;

	if (t_gnl->malloc_size - t_gnl->str_size < BUFFER_SIZE)
	{
		if (t_gnl->malloc_size < BUFFER_SIZE)
			t_gnl->malloc_size += BUFFER_SIZE;
		else
			t_gnl->malloc_size *= 2;
		tmp_str = malloc(t_gnl->malloc_size + 1);
		if (!tmp_str)
			return (-1);
		i = 0;
		while (i < t_gnl->str_size)
		{
			tmp_str[i] = t_gnl->str[i];
			i++;
		}
		free(t_gnl->str);
		t_gnl->str = tmp_str;
	}
	return (0);
}

char	*ft_substr(char *str, size_t start, size_t end)
{
	char	*return_str;
	size_t	i;

	i = 0;
	return_str = malloc(end - start + 1);
	if (!return_str)
		return (0);
	while (start < end)
	{
		return_str[i] = str[start];
		start++;
		i++;
	}
	return (return_str);
}

char	*next_line(t_gnl *t_gnl, int fd)
{
	char	*temp_str;
	char	*return_str;
	size_t	ret;

	while (1)
	{
		if (check_size(t_gnl) == -1)
		{
			printf("error\n");
			return (0);
		}
		while (t_gnl->index < t_gnl->str_size)
		{
			if (t_gnl->str[t_gnl->index] == '\n')
			{
				printf("enter\n");
				t_gnl->index++;
				return_str = ft_substr(t_gnl->str, 0, t_gnl->index);
				printf("%zu\n", t_gnl->str_size);
				temp_str = ft_substr(t_gnl->str, t_gnl->index, t_gnl->str_size);
				free(t_gnl->str);
				t_gnl->str = temp_str;
				t_gnl->str_size -= t_gnl->index;
				t_gnl->index = 0;
				t_gnl->malloc_size = t_gnl->str_size;
				return (return_str);
			}
			t_gnl->index++;
		}
		ret = read(fd, &t_gnl->str[t_gnl->str_size], BUFFER_SIZE);
		t_gnl->str_size += ret;
		if (ret == 0)
		{
			printf("eof\n");
			return_str = ft_substr(t_gnl->str, 0, t_gnl->str_size);
			temp_str = malloc(0);
			free(t_gnl->str);
			t_gnl->str = temp_str;
			t_gnl->str_size = 0;
			t_gnl->index = 0;
			t_gnl->malloc_size = 0;
			return (return_str);
		}
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	*t_gnl = 0;
	char			*return_str;

	if (!t_gnl)
	{
		t_gnl = init_t_gnl();
	}
	return_str = next_line(t_gnl, fd);
	return (return_str);
}