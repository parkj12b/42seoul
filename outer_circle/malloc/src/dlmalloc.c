#include <sys/mman.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "dlmalloc.h"
#include "globals.h"
#include "dlmchunk.h"
#include "bins.h"
#include "utils.h"
#include "dldllist.h"
#include "log.h"

t_mdata info;

int is_valid_heap(t_mchunk *chunk) {
    if (chunk == NULL)
        return 0;
    if ((void *)chunk < info.heap_start || (void *)chunk >= info.heap_start + CHUNK_SIZE)
        return 0;
    return 1;
}

t_mchunk    *split_chunk(t_mchunk *chunk, size_t size) {
    if (!is_valid_heap(chunk) || size % 16)
        abort();
    size_t next_chunk_size = chunk_size(chunk) - size;
    set_chunk_size(chunk, size);

    t_mchunk *next = next_chunk(chunk);
    set_chunk_size(next, next_chunk_size);
    next->prev_size = chunk_size(chunk);

    t_mchunk *next_next = next_chunk(next);
    if (is_valid_heap(next_next)) { 
        // probably not necessary since footer with size 16 
        // won't enter split_chunk
        next_next->prev_size = chunk_size(next);
        clear_prev_inuse(next_next);
    }
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

static t_mchunk *find_fit(size_t size) {
    t_mchunk    *return_chunk = NULL;
    int         i = get_bin_index(size);
    
    i--;
    while (return_chunk == NULL && ++i < LBIN_START) {
        if (info.bins_status & (1 << i))
            return_chunk = get_first_chunk(i);
    }
    while (return_chunk == NULL && i < NBINS) {
        if (info.bins_status & (1 << i))
            return_chunk = get_bestfit_chunk(i, size);
        i++;    
    }
    if (i >= NBINS)
        return NULL;
    if (chunk_size(return_chunk) >= size + ALIGNMENT) {
        return_chunk = split_chunk(return_chunk, size);
    }
    return (return_chunk);
}

t_mchunk    *allocate_chunk(size_t size) {
    t_mchunk    *return_chunk = NULL;

    int pagesize = align_page(size);
    return_chunk = sys_alloc(pagesize);
    if (return_chunk == NULL)
        return NULL;
    return_chunk->size = size;
    return return_chunk;
}

void    check_alignment(t_mchunk *ptr) {
    if ((size_t)ptr % ALIGNMENT != 0) {
        // handle error
        abort();
    }
}

static void *internal_malloc(size_t size) {
    t_mchunk    *chunk = NULL;
    size_t      aligned_size = ALIGN(size + 16);

    chunk = find_fit(aligned_size);
    if (chunk == NULL && aligned_size <= HPAGE_SIZE) {
        // ENOMEM
        info.flags &= ~(IN_MALLOC);
        return NULL;
    } else if (chunk != NULL) {
        t_mchunk *next = next_chunk(chunk);
        set_prev_inuse(next);
        info.flags &= ~(IN_MALLOC);
        check_alignment(chunk);
        return CHUNK_TO_USER(chunk);
    }
    chunk = allocate_chunk(aligned_size);
    info.flags &= ~(IN_MALLOC);
    check_alignment(chunk);
    return CHUNK_TO_USER(chunk);
}

void	*malloc(size_t size) {
    DLOG(write(2, "malloc called\n", 14);)

    if (!(info.flags & MALLOC_INIT)) {
        init_malloc_info();
        info.flags |= MALLOC_INIT;
    }
    if (size == 0 || (info.flags & IN_MALLOC))
        return NULL;

    info.flags |= IN_MALLOC;
    return internal_malloc(size);
}

void	*calloc(size_t n, size_t size) {
	DLOG(write(2, "calloc called\n", 14));

	if (size == 0 || n == 0)
		return NULL;

	if (size > SIZE_MAX / n)
		return NULL;

	void *ptr = internal_malloc(n * size);
	if (ptr == NULL)
		return NULL;

	memset(ptr, 0, n * size);
	return ptr;
}