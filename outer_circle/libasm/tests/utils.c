#include <time.h>
#include <stdio.h>
#include <assert.h>
#include "macros.h"
#include "utils.h"


void	timed_execution(func_ptr func, void *arg)
{
	clock_t	start, end;
	double	time_spent;

	start = clock();
	func(arg);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	PRINT(printf("Time taken: %f seconds\n\n", time_spent););
}

void    test_ft_isspace() {
    struct {
        char c;
        int expected;
    } tests[] = {
        {' ', 1},       // Space (0x20)
        {'\t', 1},      // Tab (0x09)
        {'\n', 1},      // Line feed (0x0A)
        {'\v', 1},      // Vertical tab (0x0B)
        {'\f', 1},      // Form feed (0x0C)
        {'\r', 1},      // Carriage return (0x0D)
        {'a', 0},       // Letter (0x61)
        {'0', 0},       // Digit (0x30)
        {'\x08', 0},    // Backspace (below 0x09)
        {'\x0E', 0},    // Shift out (above 0x0D)
        {'\0', 0}       // Null (0x00)
    };

    for (unsigned long i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        assert(ft_isspace(tests[i].c) == tests[i].expected);
    }

    TEST_SUCCESS;
}

void    do_nothing(void *p)
{
    (void) p;
}
