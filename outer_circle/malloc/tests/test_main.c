#include <stdio.h>
#include "test.h"

int main() {
	test_init_bin();
	test_unlink_chunk();
	test_insert_node();
	test_insert_sorted();

	// heap init test
	test_init_heap_basic();
    test_init_heap_edge_case();
    test_all_chunks_in_bins();

	// malloc/free tests
    test_malloc_and_free();

	//realloc test
	test_realloc();

	// calloc test
	test_calloc();

	// printf("All init_heap tests passed!\n");
	return 0;
}