#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include "dlmchunk.h"
#include "macros.h"
#include "dlmalloc.h"
#include "utils.h"
#include "bins.h"
#include "dldllist.h"
#include "log.h"

static t_mchunk	*coalescing(t_mchunk *cur) {
	t_mchunk *next = next_chunk(cur);
	t_mchunk *prev = NULL;

	if (!prev_inuse(cur)) {
		prev = (t_mchunk *)((char *)cur - cur->prev_size);
		unlink_chunk(prev);
		prev->size += chunk_size(cur);
		cur = prev;
	}
	if (!this_chunk_inuse(next)) {
		unlink_chunk(next);
		cur->size += chunk_size(next);
		next = next_chunk(cur);
	}
	next->prev_size = chunk_size(cur);
	clear_prev_inuse(next);
	return cur;
}

void	free(void *ptr) {
	DLOG(write(2, "free called\n", 12);)
	if (ptr == NULL) {
		return;
	}
	// if (!is_valid_heap(ptr)) {
	// 	abort();
	// }
	t_mchunk	*chunk = (t_mchunk *)(ptr - HEADER_PADDING);

	/**
	 * valid heap checks if it falls within the heap range
	 * else it's mmaped memory */ 
	if (!is_valid_heap(chunk)) {
		munmap((void *)chunk, align_page(chunk_size(chunk)));
	} else {
		t_mchunk	*free_chunk = coalescing(chunk);
		insert_chunk(free_chunk);
	}
}