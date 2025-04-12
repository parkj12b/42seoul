#include <unistd.h>
#include "globals.h"
#include "dlmchunk.h"
#include "macros.h"
#include "dlmalloc.h"
#include "dldllist.h"
#include "bins.h"

void	end_chunk(t_mchunk *cur) {
	cur->size = HPAGE_SIZE;
	t_mchunk *chunk = split_chunk(cur, HPAGE_SIZE - FOOTER_SIZE);
	chunk->prev_size = HPAGE_SIZE;
	t_mchunk *next = next_chunk(chunk);
	clear_prev_inuse(next);
	insert_chunk(chunk);
}

void	init_heap() {
	t_mchunk	*cur = info.heap_start;

	cur->size = HPAGE_SIZE;
	cur->prev_size = 0;
	set_prev_inuse(cur);
	insert_node(&(info.bins[HPAGE_IDX]), cur);
	cur = next_chunk(cur);
	while ((void *)cur < info.heap_start + CHUNK_SIZE - HPAGE_SIZE) {
		cur->size = HPAGE_SIZE;
		cur->prev_size = HPAGE_SIZE;
		// clear_prev_inuse(cur); // since we use HPAGE_SIZE for cur->size
		insert_node(info.bins[HPAGE_IDX].free_data.bk, cur);
		cur = next_chunk(cur);
	}
	end_chunk(cur);
}

void	init_malloc_info() {
	info.pagesize = sysconf(_SC_PAGESIZE);
	info.bins_status = 0;
	info.heap_start = sys_alloc(CHUNK_SIZE);
	info.flags = 0;
	for (int i = 0; i < NBINS; i++) {
		init_bin(&info.bins[i]);
	}
	init_heap();
}

size_t align_page(size_t size) {
	return (size + info.pagesize - 1) & ~(info.pagesize - 1);
}