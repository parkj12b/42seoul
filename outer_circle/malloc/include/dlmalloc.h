/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlmalloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:29 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/07 16:15:27 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLMALLOC_H
# define DLMALLOC_H

#include <stdlib.h>
#include "dlconfig.h"
#include "dlmchunk.h"

typedef struct s_malloc_info {
    size_t         pagesize;
    size_t      bins_status;
    t_mchunk    bins[NBIN];
    void        *heap_start;
    int         flags;
} t_malloc_info;

void        free(void *ptr);
void        *malloc(size_t size);
void        *realloc(void *ptr, size_t size);
void        *sys_alloc(size_t size);
void        *calloc(size_t nmemb, size_t size);
t_mchunk    *split_chunk(t_mchunk *chunk, size_t size);

#endif