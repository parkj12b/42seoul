/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:23:15 by ska               #+#    #+#             */
/*   Updated: 2023/09/11 22:44:39 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_char_buffer	*get_last(t_char_buffer *root)
{
	t_char_buffer	*prev;

	while (root)
	{
		prev = root;
		root = root->next;
	}
	return (prev);
}

void	append_char(t_char_buffer *list, char buff)
{
	t_char_buffer	*last = get_last(list);
	if (last->len == 100)
	{
		last->next = malloc(sizeof(t_char_buffer));
		last = last->next;
		last->next = 0;
		last->len = 0;
	}
	last->buffer[last->len++] = buff;
}

int	get_size(t_char_buffer *root)
{
	int	size = 0;
	
	while (root)
	{
		size += root->len;
		root = root->next;
	}
	return (size);
}

void	free_all(t_char_buffer *root)
{
	t_char_buffer	*temp;

	while (root)
	{
		temp = root;
		root = root->next;
		free(temp);
	}
}

void	copy_all(char *buff_list, t_char_buffer *list)
{
	int	i;
	int	idx;

	idx = 0;
	while (list)
	{
		i = 0;
		while (i < list->len)
			buff_list[idx++] = list->buffer[i++];
		list = list->next;
	}
}

int	get_firstline_size(char *buff_list)
{
	int	i;
	i = 0;
	while (buff_list[i] && buff_list[i] != '\n')
		i++;
	return (i);
}

int	get_number(char *buff_list, int size)
{
	int	i;
	int	res;

	if (*buff_list == '0')
		return (-1);
	i = 0;
	res = 0;
	while ('0' <= buff_list[i] && buff_list[i] <= '9' && i < size)
	{
		res = res * 10 + buff_list[i] - '0';
		i++;
	}
	if (i != size)
		return (-1);
	return (res);
}

int	set_firstline(char *buff_list, t_info *ti)
{
	int	size = get_firstline_size(buff_list);
	if (size < 4)
		return (-1);
	ti->full_char = buff_list[size - 1];
	ti->obstacle_char = buff_list[size - 2];
	ti->empty_char = buff_list[size - 3];
	ti->height = get_number(buff_list, size - 3);
	if (ti->height == -1)
		return (-1);
	return (0);
}

void	process_map(char *filename)
{
	char	buff;
	int	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	int	r = read(fd, &buff, 1);
	if (r < 0)
		return ;
	t_char_buffer	*list;
	list = malloc(sizeof(t_char_buffer));
	while (r > 0)
	{
		append_char(list, buff);
		r = read(fd, &buff, 1);
	}
	int	buff_list_size = get_size(list);
	char	*buff_list = malloc(sizeof(char) * buff_list_size);
	copy_all(buff_list, list);
	free_all(list);
	
	printf("[%s]", buff_list);
	t_info	ti;

	int ret = set_firstline(buff_list, &ti);
	if (ret == -1)
		return ;
	printf("\n\nempty=[%c], obs=[%c], full=[%c], height=[%d]\n", ti.empty_char, ti.obstacle_char, ti.full_char, ti.height);
	free(buff_list);

}

void	f(void)
{
	system("leaks a.out");
}
int main(void)
{
	atexit(f);
	process_map("testfile");
}
