#ifndef DLDLLIST_H
# define DLDLLIST_H

# include "dlmchunk.h"

void    init_bin(t_mchunk *bin);
void    unlink_chunk(t_mchunk *node);
void    insert_node(t_mchunk *prev, t_mchunk *node);
void    insert_sorted(t_mchunk *head, t_mchunk *node);

#endif