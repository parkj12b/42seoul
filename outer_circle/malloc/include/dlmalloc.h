#ifndef DLMALLOC_H
# define DLMALLOC_H

# include <stddef.h>
# include "dlmchunk.h"
# include "macros.h"


void        free(void *ptr);
void        *malloc(size_t size);
void        *realloc(void *ptr, size_t size);
void        *sys_alloc(size_t size);
void        *calloc(size_t nmemb, size_t size);
t_mchunk    *split_chunk(t_mchunk *chunk, size_t size);
int 		is_valid_heap(t_mchunk *chunk);

#endif