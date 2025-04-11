#include <stdlib.h>
#include <unistd.h>
#include "dlmchunk.h"
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
    node->free_data.fd = prev->free_data.fd;
    node->free_data.bk = prev;
    prev->free_data.fd->free_data.bk = node;
    prev->free_data.fd = node;
}

void    insert_sorted(t_mchunk *head, t_mchunk *node) {
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