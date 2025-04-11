#ifndef MACROS_H
# define MACROS_H

# define ALIGNMENT 16
# define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))
# define MIN_BLOCK_SIZE 32
# define CHUNK_SIZE (1024 * 1024)

# define NBINS 64
# define HPAGE_SIZE 2048
# define HPAGE_IDX 14
# define FOOTER_SIZE 16

# define IN_MALLOC 0x1

#endif