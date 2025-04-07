/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:11:27 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/07 16:56:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dlmchunk.h"
#include "dlmalloc.h"
#include "dlconfig.h"
#include "globals.h"
#include "utils.h"
#include "bins.h"

inline static int  is_samepage(size_t old_size, size_t new_size) {
    return ((old_size / info.pagesize) == (new_size / info.pagesize));
}

static void *realloc_large(void *ptr, size_t size) {
    t_mchunk    *chunk;
    void        *return_mem;
    size_t      old_size = chunk_size(ptr);

    if (is_samepage(old_size, size)) {
        chunk = (t_mchunk *)((char *)ptr - HEADER_PAD);
        set_chunk_size(chunk, size + HEADER_PAD);
        return ptr;
    }
    return_mem = malloc(size);
    memcpy(return_mem, ptr, MIN(old_size, size));
    chunk = (t_mchunk *)((char *)return_mem - HEADER_PAD);
    set_chunk_size(chunk, size + HEADER_PAD);
    free(ptr);
    return return_mem;
}

inline static int   is_samebin(size_t old_size, size_t new_size) {
    if (get_bin_index(old_size) == get_bin_index(new_size))
        return true;
    return false;
}

static void *realloc_small(void *ptr, size_t size) {
    t_mchunk    *chunk;
    void        *return_mem;
    size_t      old_size = chunk_size(ptr);

    if (is_samebin(old_size, size)) { // if it's a ranged bin, it still needs to change size
        chunk = (t_mchunk *)((char *)ptr - HEADER_PAD);
        set_chunk_size(chunk, size);
        if ((old_size > size) ? (old_size - size) : (size - old_size) >= 16)
            split_chunk(chunk, size + HEADER_PAD);
        return ptr;
    }
    return_mem = malloc(size);
    memcpy(return_mem, ptr, MIN(old_size, size));
    chunk = (t_mchunk *)((char *)return_mem - HEADER_PAD);
    set_chunk_size(chunk, size + HEADER_PAD);
    free(ptr);
    return return_mem;
}

void    *realloc(void *ptr, size_t size) {
    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (size > info.pagesize / 2)
        return realloc_large(ptr, size);
    return realloc_small(ptr, size);
}