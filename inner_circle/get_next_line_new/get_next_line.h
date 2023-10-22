/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:37:06 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/14 17:08:57 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# elif BUFFER_SIZE <= 0
#  error
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_node
{
	int					fd;
	size_t				cursor;
	size_t				word_size;
	struct s_fd_node	*next;
	size_t				size;
	char				*str;
}	t_fd_node;

void				*fd_deletenode(t_fd_node **front, int fd);
char				*get_next_line(int fd);
unsigned int		ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
t_fd_node			*fd_newnode(int fd);
t_fd_node			*fd_addnode(t_fd_node **front, int fd);
void				ft_lstclear(t_fd_node **lst, void (*del)(void *));
void				*ft_free(void **zmem1, void *mem2, void *mem3);
#endif
