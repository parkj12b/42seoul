/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:02:25 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/07 16:28:40 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#include "globals.h"
#include "dlmalloc.h"
#include "dldllist.h"
#include "dlmalloc.h"
#include "dlconfig.h"
#include "log.h"

/**
 * round memory address up to step aligned
 * because of malloc header size = 32, decided to get rid of 16 and 32 bin
 */
size_t align_up(size_t size, size_t step) {
    if (size <= 32)
        return 32;
    return (size + step - 1) & ~(step - 1);
}

size_t align_page(size_t size) {
    return (size + info.pagesize - 1) & ~(info.pagesize - 1);
}

#include <stdio.h>

static void init_heap(t_malloc_info *info) {
    t_mchunk    *cur = info->heap_start;
    t_mchunk    *prev = NULL;
    void        *heap_end = (char *)info->heap_start + HEAP_SIZE;

    while ((void *)cur + INIT_CHUNK_SIZE <= heap_end) {
        cur->size = INIT_CHUNK_SIZE;
        cur->prev_size = prev ? INIT_CHUNK_SIZE : 0;
        if (!prev) {
            set_prev_inuse(cur);
            DLOG(printf("it should be true: %d %p\n", prev_inuse(cur), cur);)
        }

        // Do NOT manually link fd/bk — just insert into the bin
        insert_node(&(info->bins[HPAGE_IDX]), cur);

        #include <stdio.h>
        prev = cur;
        DLOG(printf("bk: %p\n", cur->free_data.bk);)
        DLOG(printf("fd: %p\n", cur->free_data.fd);)
        cur = (t_mchunk *)((char *)cur + INIT_CHUNK_SIZE);
    }
    info->bins_status |= (1 << HPAGE_IDX);
}

void    init_malloc_info(t_malloc_info *info) {
    info->pagesize = sysconf(_SC_PAGESIZE);
    info->bins_status = 0;
    for (int i = 0; i < NBIN; i++)
        init_bin(&(info->bins[i]));
    info->heap_start = sys_alloc(HEAP_SIZE);
    init_heap(info);
    t_mchunk    *cur = &info->bins[HPAGE_IDX];
    cur = cur->free_data.fd;
    while (cur != &info->bins[HPAGE_IDX])
    {
        cur = cur->free_data.fd;
    }
}
