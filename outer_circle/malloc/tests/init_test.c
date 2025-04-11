#include <assert.h>
#include <stdio.h>
#include "globals.h"
#include "utils.h"
#include "dldllist.h"
#include "bins.h"
#include "dlmalloc.h"

void test_init_heap_basic() {
    init_malloc_info(); // This now includes init_heap

    // Verify that the heap start is not NULL
    assert(info.heap_start != NULL);

    // Verify that all bins are initialized correctly
    for (int i = 0; i < NBINS; i++) {
        if (i == HPAGE_IDX)
            continue ;
        assert(info.bins[i].free_data.fd == &info.bins[i]);
        assert(info.bins[i].free_data.bk == &info.bins[i]);
    }

    // Verify that the heap contains chunks in the expected bin
    t_mchunk *cur = info.bins[HPAGE_IDX].free_data.fd;
    while (cur != &info.bins[HPAGE_IDX]) {
        assert(cur->size == HPAGE_SIZE);
        cur = cur->free_data.fd;
    }

    printf("test_init_heap_basic passed\n");
}

void test_init_heap_edge_case() {
    init_malloc_info(); // This now includes init_heap

    // Verify that the last chunk is properly marked
    t_mchunk *last_chunk = (t_mchunk *)((char *)info.heap_start + CHUNK_SIZE - FOOTER_SIZE);
    assert(last_chunk->size == FOOTER_SIZE);
    assert(last_chunk->prev_size == HPAGE_SIZE - FOOTER_SIZE);

    printf("test_init_heap_edge_case passed\n");
}

void test_all_chunks_in_bins() {
    init_malloc_info(); // This now includes init_heap

    // Iterate through all bins
    for (int i = 0; i < NBINS; i++) {
        t_mchunk *cur = info.bins[i].free_data.fd;

        // Traverse the bin and verify all chunks are valid
        while (cur != &info.bins[i]) {
            // Check if the chunk is within the heap range
            assert(is_valid_heap(cur));

            // Check if the chunk size matches the bin index
            if (i == HPAGE_IDX) {
                assert(chunk_size(cur) == HPAGE_SIZE);
            } else if (i < HPAGE_IDX) {
                assert(chunk_size(cur) <= SBIN_MAX);
            }

            cur = cur->free_data.fd;
        }
    }

    printf("test_all_chunks_in_bins passed\n");
}
