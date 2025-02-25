#include "macros.h"
#include <time.h>
#include <stdio.h>

void	timed_execution(func_ptr func, void *arg)
{
	clock_t	start, end;
	double	time_spent;

	start = clock();
	func(arg);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time taken: %f seconds\n\n", time_spent);
}
