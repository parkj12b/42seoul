/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:24:52 by ska               #+#    #+#             */
/*   Updated: 2023/09/14 10:05:32 by ska              ###   ########.fr       */
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

typedef struct s_vector
{
	char	*buffer;
	int		idx;
	int		size;
}	t_vector;

/* solve.c */
void	char_map_to_int(t_info *map_info);
void	solve_map(t_info *map_info);
void	fill_char_map(t_info *map_info);
int		solution(t_info *map_info);

/* ft_free.c */
void	free_table_info(t_info *ti, char *buff_list);
void	free_int_map(t_info *ti);
int		free_and_return_zero(char *buff);

/* ft_info.c */
int		get_lenof_oneline(char *buff);
int		init_charmap(t_info *ti);
int		copy_size(char *buff, int size, t_info *ti, int read_height);
int		set_info(char *buff_list, t_info *ti);
void	init_info(t_info *ti);

/* ft_utils.c */
void	print_error(void);
void	print_map(t_info *map_info);
void	ft_strncpy(char *dest, char *src, unsigned int size);

/* get_firstline.c */
int		get_firstline_size(char *buff_list);
int		get_height(char *buff_list, int size);
int		examine_characters(t_info *ti);
int		set_firstline(char *buff_list, t_info *ti);

/* get_from_file.c */
int		ft_realloc(t_vector *vec);
int		read_from_file_in_vector(int fd, t_vector *vec);

/* process_map.c */
char	*get_buff_list_from_vec(t_vector *vec);
int		process_map(int fd);

/* solve_func.c */
void	map_init_sub(t_info *map_info);
int		map_init(t_info *map_info);
int		check(int i, int j, t_info *dto);

#endif
