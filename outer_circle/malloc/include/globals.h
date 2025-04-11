#ifndef GLOBALS_H
# define GLOBALS_H
# include <stddef.h>
# include "dlmchunk.h"
# include "macros.h"
typedef struct s_malloc_data {
	size_t		pagesize;
	size_t		bins_status;
	void		*heap_start; // base address of the memory pool
	t_mchunk 	bins[NBINS];
	int			flags;
} t_mdata;

extern t_mdata info;

#endif