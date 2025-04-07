/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlfree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:23:23 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/07 13:47:02 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdio.h>
#include "dlmchunk.h"
#include "dlmalloc.h"
#include "dldllist.h"
#include "bins.h"
#include "globals.h"
#include "utils.h"
#include "log.h"

static t_mchunk    *coalescing(t_mchunk *cur) {
    t_mchunk    *next = next_chunk(cur);
    t_mchunk    *prev = NULL;

    DLOG(printf("is prev in use?: %d\n", prev_inuse(cur));)
    if (!prev_inuse(cur)) {
        DLOG(printf("cur: %p, prev_size: %ld\n", cur, cur->prev_size);)
        prev = (t_mchunk *)((char *)cur - cur->prev_size);
        unlink_chunk(prev);
        prev->size += chunk_size(cur);
        cur = prev; // 
    }
    if (!this_chunk_inuse(next)) {
        unlink_chunk(next);
        cur->size += chunk_size(next);
        next = next_chunk(next); // find the new next chunk
    }
    next->prev_size = chunk_size(cur);
    clear_prev_inuse(next);
    return (cur);
}

#include <stdio.h>
void    free(void *ptr) {
    static int numfree = 0;
    numfree++;
    DLOG(printf("numfree: %d\n", numfree);)
    if (!ptr) return;
    t_mchunk    *chunk = (t_mchunk *)((char *)ptr - HEADER_PAD);

    if (chunk_size(chunk) >= info.pagesize)
        munmap((void *)chunk, align_page(chunk_size(chunk)));
    else {
        t_mchunk    *free_chunk = coalescing((t_mchunk *)chunk);
        insert_chunk(free_chunk);
    }
}