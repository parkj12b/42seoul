/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:34:09 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/14 20:04:06 by minsepar         ###   ########.fr       */
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
	new_node->fd = fd;
	new_node->endl_index = -1;
	new_node->next = 0;
	new_node->ret = 0;
	return (new_node);
}

t_fd_node	*fd_addnode(t_fd_node **front, int fd)
{
	t_fd_node	*new_node;
	t_fd_node	*cur;

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

void	*fd_deletenode(t_fd_node **front, int fd, char **dyn_str_str)
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
		free(cur);
		*front = next;
	}
	else if (cur->next && cur->next->fd == fd)
	{
		cur->next = next->next;
		free(next);
	}
	if (dyn_str_str != 0)
		ft_free((void **)dyn_str_str, 0, 0, 0);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fd_node	*front = 0;
	char				*return_ptr;
	t_dyn_char			dyn_str;
	t_fd_node			*temp;
	ssize_t				i;
	
	return_ptr = 0;
	temp = front;
	while (temp && temp->fd < fd)
		temp = temp->next;
	if (!temp || temp->fd != fd)
		temp = fd_addnode(&front, fd);
	if (!temp)
		return (0);
	i = (temp->endl_index + 1) % BUFFER_SIZE;
	if (i == 0)
		temp->ret = read(fd, temp->buf, BUFFER_SIZE);
	if (temp->ret < 0)
		return (fd_deletenode(&front, fd, 0));
	if (!malloc_str(&dyn_str, 0))
		return (fd_deletenode(&front, fd, 0));
	while (temp->ret == BUFFER_SIZE)
	{
		while (temp->buf[i] != '\n' && i + 1 < temp->ret)
			i++;
		if (!append(&dyn_str, temp->buf, (temp->endl_index + 1) % BUFFER_SIZE, i + 1))
			return (fd_deletenode(&front, fd, &dyn_str.str));
		temp->endl_index = i;
		if(temp->buf[i] == '\n')
		{
			return_ptr = ft_substr(dyn_str.str, 0, dyn_str.i);
			ft_free((void **)&dyn_str.str, 0, 0, 0);
			//free(dyn_str.str);
			//dyn_str.str = 0;
			if(!return_ptr)
				return (fd_deletenode(&front, fd, &dyn_str.str));
			//dyn_str.str = 0;
			return (return_ptr);
		}
		i = (temp->endl_index + 1) % BUFFER_SIZE;
		temp->ret = read(fd, temp->buf, BUFFER_SIZE);
		if (temp->ret < 0)
		{
			//free(dyn_str.str);
			//dyn_str.str = 0;
			ft_free((void **)&dyn_str.str, 0, 0, 0);
			return (fd_deletenode(&front, fd, &dyn_str.str));
		}
	}
	if (i >= temp->ret && !ft_strlen(dyn_str.str))
	{
		
		ft_free((void **)&dyn_str.str, 0, 0, 0);
		//free(dyn_str.str);
		//dyn_str.str = 0;
		return (fd_deletenode(&front, fd, 0));
	}
	while (temp->buf[i] != '\n' && i + 1 < temp->ret)
		i++;
	if (i < temp->ret)
		if(!append(&dyn_str, temp->buf, (temp->endl_index + 1) % BUFFER_SIZE, i + 1))
			return (fd_deletenode(&front, fd, 0));
	temp->endl_index = i;
	return_ptr = ft_substr(dyn_str.str, 0, dyn_str.i);
	free(dyn_str.str);
	if (!return_ptr)
		return (fd_deletenode(&front, fd, 0));
	return (return_ptr);
}
