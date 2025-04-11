#ifndef BINS_H
# define BINS_H

#include "dlmchunk.h"

# define LBIN_START	14
# define SBIN_STEP 	16
# define SBIN_MAX 	256

int         get_bin_index(size_t size);
void        insert_chunk(t_mchunk *chunk);
t_mchunk    *get_first_chunk(int i);
t_mchunk    *get_bestfit_chunk(int i, size_t size);

#endif