/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlmalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:50:58 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 23:02:22 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include "malloc.h"
#include "dlmchunk.h"
#include "utils.h"
#include "bins.h"
#include "dlmalloc.h"
#include "globals.h"
#include "dldllist.h"
#include "utils.h"


void *sys_alloc(size_t size) {
    void *ptr =  mmap(
        NULL, 
        size, 
        PROT_READ | PROT_WRITE, 
        MAP_PRIVATE | MAP_ANONYMOUS, 
        -1, 
        0
    );
    if (ptr == MAP_FAILED)
        return NULL;
    return ptr;
}

/**
 * helper function to split chunk if chunk too large.
 */
static t_mchunk *split_chunk(t_mchunk *chunk, size_t size) {
    size_t next_chunk_size = chunk_size(chunk) - size;
    chunk->size = size;
    
    t_mchunk    *next = next_chunk(chunk);
    next->size = next_chunk_size;
    next->prev_size = chunk_size(chunk);
    set_prev_inuse(next);
    insert_chunk(next);
    return (chunk);
}

/**
 * size_t   size,   aligned address passed from malloc to be allocated 
 *                  including sizeof malloc header
 */
static t_mchunk *find_fit(size_t size) {
    t_mchunk    *return_chunk = NULL;
    int i = get_bin_index(size);
    int counter = i - 1;

    while (return_chunk == NULL && ++counter < LBIN_START) {
        if (info.bins_status & (1 << counter))
            return_chunk = get_first_chunk(counter);
    }
    while (return_chunk == NULL && counter < NBIN) {
        if (info.bins_status & (1 << counter))
            return_chunk = get_bestfit_chunk(counter, size);
        counter++;
    }
    printf("return_chunk: %p\n", return_chunk);
    printf("can't be %p\n", info.bins[HPAGE_IDX].free_data.fd);
    if (counter >= NBIN)
        return NULL;
    if (chunk_size(return_chunk) - size >= SBIN_MIN)
        return_chunk = split_chunk(return_chunk, size);
    return return_chunk;
}

t_mchunk    *allocate_chunk(size_t size) {
    t_mchunk    *return_chunk;

    int pagesize = align_page(size);
    return_chunk = sys_alloc(pagesize);
    return_chunk->size = pagesize;
    return return_chunk;
}

void    *ft_malloc(size_t size) {
    static char *welcome = "calling custom malloc\n";
    static char *success = "allocated ?\n";
    static char *ohno = "error\n";
    write(1, welcome, strlen(welcome));
    t_mchunk    *chunk = NULL;

    size_t  aligned_size = align_up(size + HEADER_PAD, SMALL_BIN_STEP);
    
    if (aligned_size <= info.pagesize / 2) {
        chunk = find_fit(aligned_size);
        if (chunk == NULL) {
            write(1, ohno, strlen(ohno));
            errno = ENOMEM;
            return (NULL);
        }
        set_prev_inuse(next_chunk(chunk));
    }
    else
        chunk = allocate_chunk(aligned_size);
    write(1, success, strlen(success));
    return chunk->user_data;
}
