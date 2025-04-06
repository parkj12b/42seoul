/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bins.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:07:37 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 23:29:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlmalloc.h"
#include "bins.h"
#include "globals.h"
#include "utils.h"
#include "dldllist.h"
#include "dlmchunk.h"

/**
 * logarithmic bin mapping
 */
static int get_lbin_index(size_t size) {
    int index = LBIN_START;

    size >>= 8;
    while (size != 0) {
        size >>=1;
        index++;
    }

    return index;
}

static int get_sbin_index(size_t size) {
    return ((align_up(size, SMALL_BIN_STEP) - 16) / SMALL_BIN_STEP) - 1;
}

int get_bin_index(size_t size) {
    if (size <= SBIN_MAX) {
        return get_sbin_index(size);
    } else  {
        return get_lbin_index(size);
    }
}

void    insert_chunk(t_mchunk *chunk) {
    int i;

    i = get_bin_index(chunk_size(chunk));
    if (chunk_size(chunk) <= SBIN_MAX) {
        insert_node(&info.bins[i], chunk);
    } else {
        insert_sorted(&info.bins[i], chunk);
    }
    
    //if insert bin was empty make it non empty flag
    if (!(info.bins_status & (1 << i)))
        info.bins_status |= (1 << i);
}

/**
 * returns NULL if list empty
 */
t_mchunk *get_first_chunk(int i) {
    t_mchunk    *cur = &info.bins[i];
    
    cur = cur->free_data.fd;
    if (&info.bins[i] == cur)
        return NULL;
    unlink_chunk(cur);
    if (info.bins[i].free_data.fd == &info.bins[i])
        info.bins_status &= ~(1 << i);
    return cur;
}

#include <stdio.h>
/**
 * returns NULL if list empty 
 */
t_mchunk *get_bestfit_chunk(int i, size_t size) {
    t_mchunk    *bin = &info.bins[i];
    t_mchunk    *cur = info.bins[i].free_data.fd;

    if (cur == bin)
        return NULL;
    printf("bin: %p\n", bin);
    printf("cur: %p\n", cur);
    while (cur != &info.bins[i] && chunk_size(cur) > size) {
        cur = cur->free_data.fd;
    }
    if (chunk_size(cur) == size) {
        unlink_chunk(cur);
        return cur;
    }
    
    t_mchunk    *temp = cur->free_data.bk;
    unlink_chunk(temp);
    return temp;
}