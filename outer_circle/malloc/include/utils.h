/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:12:33 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/07 16:46:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "dlmalloc.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

size_t  align_up(size_t size, size_t step);
size_t  align_page(size_t size);
void    init_malloc_info(t_malloc_info *info);   

#endif