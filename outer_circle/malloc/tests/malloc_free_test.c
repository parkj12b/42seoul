#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "globals.h"
#include "utils.h"
#include "dlmalloc.h"
#include "dlmchunk.h"
#include "log.h"
#include "macros.h"
#include "dldllist.h"
#include "test.h"

// Helper function to check alignment
int is_aligned(void *ptr, size_t alignment) {
    return ((uintptr_t)ptr % alignment) == 0;
}

// Helper function to check if memory is zeroed
int is_zeroed(void *ptr, size_t size) {
    unsigned char *bytes = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        if (bytes[i] != 0) {
            return 0;
        }
    }
    return 1;
}
#include <sys/mman.h>
#include "macros.h"

// Test basic malloc functionality
void test_basic_malloc() {
    printf("Running test_basic_malloc...\n");
    
    // Test small allocation
    void *ptr1 = malloc(16);
    assert(ptr1 != NULL);
    assert(is_aligned(ptr1, ALIGNMENT));
    
    // Test medium allocation
    void *ptr2 = malloc(256);
    assert(ptr2 != NULL);
    assert(is_aligned(ptr2, ALIGNMENT));
    
    // Test larger allocation
    void *ptr3 = malloc(1024);
    assert(ptr3 != NULL);
    assert(is_aligned(ptr3, ALIGNMENT));
    
    // Clean up
    free(ptr1);
    free(ptr2);
    free(ptr3);
    
    printf("test_basic_malloc passed!\n");
}

// Test basic free functionality
void test_basic_free() {
    printf("Running test_basic_free...\n");
    
    // Allocate and immediately free
    void *ptr = malloc(64);
    assert(ptr != NULL);
    free(ptr);
    
    // Allocate again to check if memory is reused
    void *ptr2 = malloc(32);
    assert(ptr2 != NULL);
    
    // Should be able to free NULL without errors
    free(NULL);
    
    // Clean up
    free(ptr2);
    
    printf("test_basic_free passed!\n");
}

// Test multiple allocations and frees
void test_multiple_allocs() {
    printf("Running test_multiple_allocs...\n");
    
    #define NUM_ALLOCS 100
    #define ALLOC_SIZE 32
    
    void *ptrs[NUM_ALLOCS];
    
    // Allocate multiple blocks
    for (int i = 0; i < NUM_ALLOCS; i++) {
        ptrs[i] = malloc(ALLOC_SIZE);
        assert(ptrs[i] != NULL);
        
        // Write pattern to memory
        memset(ptrs[i], i % 256, ALLOC_SIZE);
    }
    
    // Verify patterns
    for (int i = 0; i < NUM_ALLOCS; i++) {
        unsigned char *mem = (unsigned char *)ptrs[i];
        for (int j = 0; j < ALLOC_SIZE; j++) {
            assert(mem[j] == (i % 256));
        }
    }
    
    // Free every other block
    for (int i = 0; i < NUM_ALLOCS; i += 2) {
        free(ptrs[i]);
        ptrs[i] = NULL;
    }
    
    // Allocate again to check memory reuse
    for (int i = 0; i < NUM_ALLOCS; i += 2) {
        ptrs[i] = malloc(ALLOC_SIZE);
        assert(ptrs[i] != NULL);
    }
    
    // Clean up
    for (int i = 0; i < NUM_ALLOCS; i++) {
        free(ptrs[i]);
    }
    
    printf("test_multiple_allocs passed!\n");
}

// Test coalescing of adjacent free chunks
void test_coalescing() {
    reset_heap();
    printf("Running test_coalescing...\n");
    
    // Allocate three adjacent blocks
    void *ptr1 = malloc(128);
    void *ptr2 = malloc(128);
    void *ptr3 = malloc(128);
    
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    assert(ptr3 != NULL);
    
    // Free them in reverse order
    free(ptr3);
    free(ptr2);
    
    // Now attempt to allocate a block that should fit in the coalesced space
    void *large_ptr = malloc(300);
    assert(large_ptr != NULL);
    // Should be at the same address as the first allocation
    assert(large_ptr == ptr2);
    
    // Clean up
    free(large_ptr);
    free(ptr1);
    
    printf("test_coalescing passed!\n");
}

// Test allocation of different sizes
void test_various_sizes() {
    reset_heap();
    printf("Running test_various_sizes...\n");
    
    // Array of sizes to test
    size_t sizes[] = {
        1, 2, 3, 4, 8, 15, 16, 17, 
        32, 64, 128, 256, 512, 1024, 
        HPAGE_SIZE - 32, HPAGE_SIZE, HPAGE_SIZE + 32
    };
    
    void *ptrs[sizeof(sizes) / sizeof(sizes[0])];
    
    // print_free_list();
    // Allocate various sizes
    for (size_t i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        ptrs[i] = malloc(sizes[i]);
        assert(ptrs[i] != NULL);
        
        // Write to memory to ensure it's usable
        memset(ptrs[i], 0xAB, sizes[i]);
        
        // Check that we can read back what we wrote
        unsigned char *mem = (unsigned char *)ptrs[i];
        for (size_t j = 0; j < sizes[i]; j++) {
            assert(mem[j] == 0xAB);
        }
    }
    
    // Free in reverse order
    for (int i = sizeof(sizes) / sizeof(sizes[0]) - 1; i >= 0; i--) {
        free(ptrs[i]);
    }
    
    printf("test_various_sizes passed!\n");
}

// Test for leaks and heap organization
void test_heap_organization() {
    printf("Running test_heap_organization...\n");
    
    // First, allocate to clear the heap structure
    void *big_block = malloc(CHUNK_SIZE / 2);
    assert(big_block != NULL);
    free(big_block);
    
    // Record initial bin status
    size_t initial_bins_status = info.bins_status;
    
    // Allocate and free to test bin reuse
    void *blocks[10];
    for (int i = 0; i < 10; i++) {
        blocks[i] = malloc(HPAGE_SIZE / 2);
        assert(blocks[i] != NULL);
    }
    
    // Free all blocks
    for (int i = 0; i < 10; i++) {
        free(blocks[i]);
    }
    
    // Bins status should return to same state (or better)
    // This check might need adjustment based on your allocator behavior
    assert((info.bins_status & initial_bins_status) == initial_bins_status);
    
    printf("test_heap_organization passed!\n");
}

// Test very large allocations near/at heap limit
void test_extreme_large_allocs() {
    reset_heap();
    printf("Running test_extreme_large_allocs...\n");
    
    // Try allocating something close to CHUNK_SIZE
    void *big = malloc(CHUNK_SIZE - 1024);
    if (big != NULL) {
        // If succeeded, try to write to it
        memset(big, 0x42, 1024); // Write to first 1KB to verify usability
        free(big);
    } else {
        printf("Large allocation failed (expected if heap is too small)\n");
    }
    
    // Try multiple medium-large allocations
    const int num_allocs = 5;
    void *ptrs[num_allocs];
    size_t alloc_size = CHUNK_SIZE / (num_allocs * 2);
    
    printf("Attempting %d allocations of size %zu\n", num_allocs, alloc_size);
    
    int success_count = 0;
    for (int i = 0; i < num_allocs; i++) {
        ptrs[i] = malloc(alloc_size);
        if (ptrs[i] != NULL) {
            success_count++;
            // Mark the memory
            memset(ptrs[i], i+1, 16);
        }
    }
    
    printf("Successfully allocated %d/%d large blocks\n", success_count, num_allocs);
    
    // Free in reverse order
    for (int i = success_count-1; i >= 0; i--) {
        free(ptrs[i]);
    }
    
    printf("test_extreme_large_allocs completed\n");
}

// Test many tiny allocations to stress the small bin behavior
void test_extreme_tiny_allocs() {
    reset_heap();
    printf("Running test_extreme_tiny_allocs...\n");
    
    #define TINY_COUNT 10000
    #define TINY_SIZE 1
    
    void *ptrs[TINY_COUNT];
    int success_count = 0;
    
    for (int i = 0; i < TINY_COUNT; i++) {
        ptrs[i] = malloc(TINY_SIZE);
        if (ptrs[i] != NULL) {
            success_count++;
            // Write a single byte
            *((char*)ptrs[i]) = i % 256;
        } else {
            break; // Stop if we can't allocate more
        }
    }
    
    printf("Successfully allocated %d/%d tiny blocks\n", success_count, TINY_COUNT);
    
    // Verify our data
    for (int i = 0; i < success_count; i++) {
        char expected = i % 256;
        assert(*((char*)ptrs[i]) == expected);
    }
    
    // Free in a pattern designed to create fragmentation
    // Free every third block first
    for (int i = 0; i < success_count; i += 3) {
        free(ptrs[i]);
        ptrs[i] = NULL;
    }
    
    // Then free every second remaining block
    for (int i = 1; i < success_count; i += 2) {
        if (ptrs[i] != NULL) {
            free(ptrs[i]);
            ptrs[i] = NULL;
        }
    }
    
    // Free the rest
    for (int i = 0; i < success_count; i++) {
        if (ptrs[i] != NULL) {
            free(ptrs[i]);
        }
    }
    
    printf("test_extreme_tiny_allocs passed!\n");
}

// Test allocation of edge cases and unusual sizes
void test_edge_cases() {
    reset_heap();
    printf("Running test_edge_cases...\n");
    
    // Test malloc(0)
    void *zero_ptr = malloc(0);
    if (zero_ptr == NULL) {
        printf("malloc(0) returns NULL as expected\n");
    } else {
        printf("malloc(0) returns non-NULL pointer (implementation choice)\n");
        free(zero_ptr);
    }
    
    // Test alignment with odd sizes
    size_t odd_sizes[] = {3, 7, 11, 15, 23, 33, 63, 127, 129};
    for (size_t i = 0; i < sizeof(odd_sizes)/sizeof(odd_sizes[0]); i++) {
        void *ptr = malloc(odd_sizes[i]);
        assert(ptr != NULL);
        assert(is_aligned(ptr, ALIGNMENT));
        
        // Write to all bytes to check usability
        memset(ptr, 0xAA, odd_sizes[i]);
        free(ptr);
    }
    
    // Test very large allocation
    size_t large_size = CHUNK_SIZE - 4096; // Just under heap size
    void *large_ptr = malloc(large_size);
    if (large_ptr != NULL) {
        // Touch the first and last byte
        *((char*)large_ptr) = 1;
        *((char*)large_ptr + large_size - 1) = 1;
        free(large_ptr);
    } else {
        printf("Very large allocation failed (expected if heap is small)\n");
    }
    
    printf("test_edge_cases passed!\n");
}

// Test that creates extreme fragmentation
void test_fragmentation() {
    reset_heap();
    printf("Running test_fragmentation...\n");
    
    #define FRAG_ALLOCS 100
    void *ptrs[FRAG_ALLOCS];
    
    // Allocate alternating small and large blocks
    for (int i = 0; i < FRAG_ALLOCS; i++) {
        if (i % 2 == 0) {
            ptrs[i] = malloc(16); // Small blocks
        } else {
            ptrs[i] = malloc(256); // Larger blocks
        }
        assert(ptrs[i] != NULL);
        
        // Write a pattern to memory
        memset(ptrs[i], i % 256, i % 2 == 0 ? 16 : 256);
    }
    
    // Free all the small blocks
    for (int i = 0; i < FRAG_ALLOCS; i += 2) {
        free(ptrs[i]);
    }
    
    // Now try to allocate medium blocks that won't fit in the small gaps
    int success_count = 0;
    for (int i = 0; i < FRAG_ALLOCS/2; i++) {
        void *medium = malloc(128);
        if (medium != NULL) {
            success_count++;
            free(medium);
        } else {
            break;
        }
    }
    
    printf("Successfully allocated %d medium blocks after fragmentation\n", success_count);
    
    // Clean up the large blocks
    for (int i = 1; i < FRAG_ALLOCS; i += 2) {
        free(ptrs[i]);
    }
    
    printf("test_fragmentation completed\n");
}

// Rapid allocation/free cycles
void test_rapid_cycles() {
    reset_heap();
    printf("Running test_rapid_cycles...\n");
    
    for (int cycle = 0; cycle < 1000; cycle++) {
        void *p1 = malloc(cycle % 128 + 1);
        void *p2 = malloc(cycle % 256 + 1);
        void *p3 = malloc(cycle % 512 + 1);
        
        assert(p1 != NULL);
        assert(p2 != NULL);
        assert(p3 != NULL);
        
        // Write some data
        if (p1) *((char*)p1) = 'A';
        if (p2) *((char*)p2) = 'B';
        if (p3) *((char*)p3) = 'C';
        
        free(p2);
        
        void *p4 = malloc(cycle % 64 + 1);
        assert(p4 != NULL);
        
        free(p1);
        free(p3);
        free(p4);
        
        if (cycle % 100 == 0) {
            printf("Completed %d rapid cycles\n", cycle);
        }
    }
    
    printf("test_rapid_cycles passed!\n");
}

// Run all tests
void run_malloc_free_tests() {
    printf("Starting malloc and free tests...\n");
    
    test_basic_malloc();
    test_basic_free();
    test_multiple_allocs();
    test_coalescing();
    test_various_sizes();
    test_heap_organization();
    
    // Add the extreme tests
    test_extreme_large_allocs();
    test_extreme_tiny_allocs();
    test_edge_cases();
    test_fragmentation();
    test_rapid_cycles();
    
    printf("All malloc and free tests passed!\n");
}

// Test function to add to your main test file
void test_malloc_and_free() {
    run_malloc_free_tests();
}
