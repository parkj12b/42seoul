/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlmchunk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:33:48 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 18:02:57 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLMCHUNK_H
# define DLMCHUNK_H

# include <stddef.h>
# include "dlconfig.h"

typedef struct s_malloc_chunk {
    size_t prev_size; // only valid if previous chunk is free
    size_t size;      // contains size + prev_inuse bit
    union {
        struct {
            struct s_malloc_chunk *fd;
            struct s_malloc_chunk *bk;
        } free_data; // only used when chunk is free
        char user_data[1]; // placeholder for user allocation
    };
} t_mchunk;


static inline size_t chunk_size(t_mchunk *chunk) {
    return chunk->size & ~(PREV_INUSE);
}

static inline int prev_inuse(t_mchunk *chunk) {
    return chunk->size & PREV_INUSE;
}

static inline void set_prev_inuse(t_mchunk *chunk) {
    chunk->size |= PREV_INUSE;
}

static inline void clear_prev_inuse(t_mchunk *chunk) {
    chunk->size &= ~PREV_INUSE;
}

static inline t_mchunk* next_chunk(t_mchunk *chunk) {
    return (t_mchunk *)((char *)chunk + chunk_size(chunk));
}

static inline int this_chunk_inuse(t_mchunk *chunk) {
    t_mchunk *next = next_chunk(chunk);
    return next->size & PREV_INUSE;
}

#endif