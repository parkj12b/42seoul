#include "dlmchunk.h"
#include "dlmalloc.h"

int this_chunk_inuse(t_mchunk *chunk) {
    t_mchunk *next = next_chunk(chunk);
    if (!is_valid_heap(next)) // footer chunk validation
        return 1;
    return next->size & PREV_INUSE;
}
