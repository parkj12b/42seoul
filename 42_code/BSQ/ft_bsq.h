/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:24:52 by ska               #+#    #+#             */
/*   Updated: 2023/09/11 22:44:40 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <stdio.h>
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
}	t_info;

typedef struct s_char_buffer
{
	char					buffer[100];
	int						len;
	struct s_char_buffer	*next;
}	t_char_buffer;

#endif
