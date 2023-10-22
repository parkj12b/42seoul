/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:51:49 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/13 17:03:46 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <libgen.h>

void	print_node(t_fd_node *node)
{
	printf("addr: %p\n", node);
	printf("fd: %d\n", node->fd);
	printf("endl_index: %zu\n", node->endl_index);
}

void	check_leak(void)
{
	system("leaks a.out");
}

int		main()
{
	//atexit(check_leak);
	
	t_fd_node *front = 0;

	fd_addnode(&front, 3);
	fd_addnode(&front, 1);
	fd_addnode(&front, 10);
	
	while (front)
	{
		print_node(front);
		front = front->next;
	}
	
	fd_deletenode(&front, 1, 0);
	fd_deletenode(&front, 3, 0);
	/*
	//print_node(front);	
	while (front)
	{
		print_node(front);
		front = front->next;
	}
	*/
/*	
	int fd = open("giant_line.txt", O_RDONLY);
	//char c;
	char *s;
	while ((s = get_next_line(fd)))
	{
		printf("%s len: (%u)\n", s, ft_strlen(s));
		free(s);
	}
	
	close(fd);
	fd = open("test", O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	*/
/*
	scanf("%c", &c);
	while (c == '\n')
	{
		s= get_next_line(fd);
		printf("%s", s);
		scanf("%c", &c);
		free(s);
	}	
	*/
	/*
	int fd = open("test", O_RDONLY);
	char	c;
	scanf("%c", &c);
	while (c == '\n')
	{
		printf("%s\n", get_next_line(fd));
		scanf("%c", &c);
	}
	
	*/
}
