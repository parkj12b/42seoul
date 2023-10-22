/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:37:06 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/13 14:39:51 by minsepar         ###   ########.fr       */
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
	ssize_t				endl_index;
	char				buf[BUFFER_SIZE];
	struct s_fd_node	*next;
	ssize_t				ret;
}	t_fd_node;

typedef struct s_dyn_char
{
	size_t	i;
	size_t	size;
	char	*str;
}	t_dyn_char;


void *ft_free(void **zmeme, void *mem2, void *mem3, void *mem4);
void				*fd_deletenode(t_fd_node **front, int fd, char **dyn_str_str);
char				*get_next_line(int fd);
unsigned int		ft_strlen(const char *str);
char				*ft_strjoin_free(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
t_fd_node			*fd_newnode(int fd);
t_fd_node			*fd_addnode(t_fd_node **front, int fd);
void				ft_lstclear(t_fd_node **lst, void (*del)(void *));
void				*malloc_str(t_dyn_char *dyn_str, size_t len);
void				*append(t_dyn_char *dyn_str, char *str, size_t start, size_t end);
#endif
