/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dldllist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:36:40 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 23:33:13 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlmalloc.h"
#include "globals.h"
#include "bins.h"

void    init_bin(t_mchunk *bin) {
    bin->free_data.fd = bin;
    bin->free_data.bk = bin;
}

void    unlink_chunk(t_mchunk *node) {
    t_mchunk *fd = node->free_data.fd;
    t_mchunk *bk = node->free_data.bk;
    fd->free_data.bk = bk;
    bk->free_data.fd = fd;

    int i = get_bin_index(chunk_size(node));
    if (info.bins[i].free_data.fd == &info.bins[i])
        info.bins_status &= ~(1 << i);
}
#include <stdio.h>
void    insert_node(t_mchunk *prev, t_mchunk *node) {
    printf("prev: %p node: %p\n", prev, node);
    node->free_data.fd = prev->free_data.fd;
    node->free_data.bk = prev;
    prev->free_data.fd->free_data.bk = node;
    prev->free_data.fd = node;
}

#include <stdio.h>
/**
 * No need to use chunk_size since it's already in the bin. 
 */
void    insert_sorted(t_mchunk *head, t_mchunk *node) {
    t_mchunk    *cur = head->free_data.fd;

    while (cur != head && chunk_size(cur) > chunk_size(node)) {
        cur = cur->free_data.fd;
    }
    printf("cur: %p\n", cur);
    insert_node(cur->free_data.bk, node);
}