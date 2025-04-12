#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "dlmchunk.h"
#include "globals.h"
#include "dlmalloc.h"
#include "bins.h"

void    init_bin(t_mchunk *bin) {
    bin->free_data.fd = bin;
    bin->free_data.bk = bin;
}

void    unlink_chunk(t_mchunk *node) {
    if (node->size < MIN_BLOCK_SIZE) {
        return ;
    }
    t_mchunk *fd = node->free_data.fd;
    t_mchunk *bk = node->free_data.bk;
    fd->free_data.bk = bk;
    bk->free_data.fd = fd;

    int i = get_bin_index(chunk_size(node));
    if (info.bins[i].free_data.fd == &info.bins[i])
        info.bins_status &= ~(1 << i);
}

int is_bin(t_mchunk *node) {
    for (int i = 0; i < NBINS; i++) {
        if (node == &info.bins[i])
            return 1;
    }
    return 0;
}

void    insert_node(t_mchunk *prev, t_mchunk *node) {
    // if (!is_bin(node) && !is_valid_heap(node))
    //     abort();
    node->free_data.fd = prev->free_data.fd;
    node->free_data.bk = prev;
    prev->free_data.fd->free_data.bk = node;
    prev->free_data.fd = node;
}

void    insert_sorted(t_mchunk *head, t_mchunk *node) {
    // if (!is_valid_heap(node)) // for testing
    //     abort();
    t_mchunk    *cur = head->free_data.fd;
    size_t      node_size = chunk_size(node);

    if (head == node)
        return;
    while (cur != head && chunk_size(cur) > node_size) {
        cur = cur->free_data.fd;
    }
    if (cur != head && cur == cur->free_data.fd) {
        write(2, "corrupted bin\n", 14);
        abort();
    }
    insert_node(cur->free_data.bk, node);
}