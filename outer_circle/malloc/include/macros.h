#ifndef MACROS_H
# define MACROS_H

# define ALIGN(size)        (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))
# define CHUNK_TO_USER(ptr) (void *)((char *)(ptr) + HEADER_PADDING)
# define ALIGNMENT          16
# define HEADER_PADDING     16
# define MIN_BLOCK_SIZE     32
# define CHUNK_SIZE         (16 * 1024 * 1024)

# define NBINS              64
# define HPAGE_SIZE         2048
# define HPAGE_IDX          17
# define FOOTER_SIZE        16

/* info.status_flag */
# define IN_MALLOC          0x1
# define MALLOC_INIT        0x2

# define SBIN_MAX           256

#endif