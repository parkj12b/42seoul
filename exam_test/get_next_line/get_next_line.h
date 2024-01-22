/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:53:35 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/19 15:02:08 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_gnl
{
    char	*str;
    size_t	malloc_size;
	size_t	str_size;
	size_t	index;
}   t_gnl;

#endif