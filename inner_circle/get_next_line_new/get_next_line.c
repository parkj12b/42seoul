/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:34:09 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/14 17:25:51 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_fd_node *fd_newnode(int fd)
{
	t_fd_node *new_node;

	new_node = (t_fd_node *)malloc(sizeof(t_fd_node));
	if (!new_node)
		return (0);
	new_node->str = (char *)malloc(BUFFER_SIZE + 1);
	if (!new_node->str)
	{
		free(new_node);
		return (0);
	}
	new_node->str[0] = 0;
	new_node->size = BUFFER_SIZE;
	new_node->cursor = 0;
	new_node->word_size = 0;
	new_node->fd = fd;
	new_node->next = 0;
	return (new_node);
}

t_fd_node	*fd_addnode(t_fd_node **front, int fd)
{
	t_fd_node   *new_node;
	t_fd_node   *cur;

	cur = *front;
	new_node = fd_newnode(fd);
	if (!new_node)
		return (0);
	if (!*front || (*front)->fd > fd)
	{
		*front = new_node;
		(*front)->next = cur;
	}
	else
	{
		while (cur->next && cur->next->fd < fd)
			cur = cur->next;
		new_node->next = cur->next;
		cur->next = new_node;
	}
	return (new_node);
}

void	*fd_deletenode(t_fd_node **front, int fd)
{
	t_fd_node *cur;
	t_fd_node *next;

	if (!front || !*front)
		return (0);
	cur = *front;
	next = cur->next;
	while (cur->next && cur->next->fd < fd)
	{
		cur = cur->next;
		next = cur->next;
	}
	if ((*front)->fd == fd)
	{
		ft_free((void **)&cur->str, cur, 0);
		*front = next;
	}
	else if (cur->next && cur->next->fd == fd)
	{
		cur->next = next->next;
		ft_free((void **)&next->str, next, 0);
	}
	return (0);
}

void	*ft_free(void **zmem1, void *mem2, void *mem3)
{
	if (zmem1)
	{
		free(*zmem1);
		*zmem1 = 0;
	}
	free(mem2);
	free(mem3);
	return (0);
}

char	*ft_read_line(int fd, t_fd_node *cur, t_fd_node **front)
{
	ssize_t	ret;
	char	*temp;
	char	*save_str;
	ssize_t	temp_i;

	while (1)
	{
		if (cur->word_size + BUFFER_SIZE > cur->size)
		{
			cur->size = (cur->size < BUFFER_SIZE) * (BUFFER_SIZE + cur->word_size)
				+ !(cur->size < BUFFER_SIZE) * (cur->size * 2);
			temp = (char *)malloc(cur->size + 1);
			if (!temp)
				return (fd_deletenode(front, fd));
			temp_i = cur->word_size;
			while (temp_i-- > 0)
				temp[temp_i] = cur->str[temp_i];
			free(cur->str);
			cur->str = temp;
		}
		ret = read(fd, &cur->str[cur->word_size], BUFFER_SIZE);
		if (ret < 0)
			return (fd_deletenode(front, fd));
		cur->word_size += ret;
		cur->str[cur->word_size] = 0;
		while (cur->str[cur->cursor] && cur->str[cur->cursor] != '\n')
			cur->cursor++;
		if ((cur->str[cur->cursor] == '\n') || (cur->cursor > 0 && ret == 0))
		{
			if (cur->str[cur->cursor] == '\n')
				cur->cursor++;
			temp = ft_substr(cur->str, 0, cur->cursor);
			save_str = ft_substr(cur->str, cur->cursor, cur->word_size - cur->cursor); 
			if (!temp || !save_str)
				if(!ft_free(0, temp, save_str))
					return (fd_deletenode(front, fd));
			cur->size = cur->word_size - cur->cursor;
			cur->word_size = cur->size;
			cur->cursor = 0;
			free(cur->str);
			cur->str = save_str;
			return (temp);
		} else if(cur->word_size == 0 && ret == 0)
			return (fd_deletenode(front, fd));
	}
}

char	*get_next_line(int fd)
{
	static t_fd_node	*front = 0;
	t_fd_node			*cur;
	char				*return_str;

	cur = front;
	while(cur && cur->fd < fd)
		cur = cur->next;
	if(!cur || cur->fd != fd)
		cur = fd_addnode(&front, fd);
	if(!cur)
		return (0);
	return_str = ft_read_line(fd, cur, &front);
	return (return_str);
}

