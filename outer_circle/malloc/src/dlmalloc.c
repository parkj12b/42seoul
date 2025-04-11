#include <sys/mman.h>
#include <unistd.h>
#include "dlmalloc.h"
#include "globals.h"
#include "dlmchunk.h"
#include "bins.h"

t_mdata info;

int is_valid_heap(t_mchunk *chunk) {
    if (chunk == NULL)
        return 0;
    if ((void *)chunk < info.heap_start || (void *)chunk >= info.heap_start + CHUNK_SIZE)
        return 0;
    return 1;
}

t_mchunk    *split_chunk(t_mchunk *chunk, size_t size) {
    size_t next_chunk_size = chunk_size(chunk) - size;
    set_chunk_size(chunk, size);

    t_mchunk *next = next_chunk(chunk);
    set_chunk_size(next, next_chunk_size);
    next->prev_size = size;
    insert_chunk(next);
    return chunk;
}

void *sys_alloc(size_t size) {
    void *ptr =  mmap(
        NULL, 
        size, 
        PROT_READ | PROT_WRITE, 
        MAP_PRIVATE | MAP_ANONYMOUS, 
        -1, 
        0
    );
    if (ptr == MAP_FAILED)
        return NULL;
    return ptr;
}

void	*malloc(size_t size) {
    t_mchunk    *chunk = NULL;
    (void) chunk;
    if (size == 0)
        return NULL;
    if (info.flags & IN_MALLOC) return NULL;
    info.flags |= IN_MALLOC;
    return NULL;
}