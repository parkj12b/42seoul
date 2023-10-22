/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:24:52 by ska               #+#    #+#             */
/*   Updated: 2023/09/13 20:54:29 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_info
{
	int		height;
	int		width;
	char	**char_map;
	char	empty_char;
	char	full_char;
	char	obstacle_char;
	int		**map;
	int		dy[4];
	int		dx[4];
	int		answer;
	int		answer_y;
	int		answer_x;
}	t_info;

typedef struct s_char_buffer
{
	char					buffer[2048];
	int						len;
	struct s_char_buffer	*next;
}	t_char_buffer;

typedef struct s_linked_list
{
	t_char_buffer	*head;
	t_char_buffer	*tail;
}	t_linked_list;

/* solve.c */
void			solution(t_info *map_info);
void			fill_char_map(t_info *map_info);
void			solve_map(t_info *map_info);
void			print_map(t_info *map_info);
void			char_map_to_int(t_info *map_info);

/* ft_free.c */
void			free_all(t_char_buffer *root);
void			free_table_info(t_info *ti, char *buff_list);
void			free_int_map(t_info *ti);

/* ft_info.c */
int				get_lenof_oneline(char *buff);
int				copy_size(char *buff, int size, t_info *ti, int read_height);
int				set_info(char *buff_list, t_info *ti);
void			init_info(t_info *ti);

/* get_buff_list.c */
int				get_size(t_char_buffer *root);
char			*get_buff_list(t_char_buffer *head);

/* error.c */
void			print_error(void);

/* get_firstline.c */
int				get_firstline_size(char *buff_list);
int				get_height(char *buff_list, int size);
int				examine_characters(t_info *ti);
int				set_firstline(char *buff_list, t_info *ti);

/* get_from_file.c */
void			append_char(t_linked_list *list, char buff);
t_char_buffer	*get_new_buffer(void);
int				read_from_file(int fd, t_linked_list *list);

/* process_map.c */
int				process_map(int fd);

/* debug.c */
void			print_map(t_info *map_info);
void			f(void);

/* solve_func.c */
void			map_init(t_info *map_info);
int				check(int i, int j, t_info *dto);
void			int_map_init(t_info *map_info);

#endif
