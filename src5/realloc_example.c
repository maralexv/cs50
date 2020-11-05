// crt_realloc.c
// This program allocates a block of memory for
// buffer and then uses _msize to display the size of that
// block. Next, it uses realloc to expand the amount of
// memory used by buffer and then calls _msize again to
// display the new amount of memory allocated to buffer.

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

int main(void)
{
    long *buffer, *oldbuffer;
    size_t size;

    if ((buffer = (long *)malloc(1000 * sizeof(long))) == NULL)
        return 1;

    size = malloc_size(buffer);
    printf("Size of block after malloc of 1000 longs: %zu\n", size);

    // Reallocate and show new size:
    oldbuffer = buffer; // save pointer in case realloc fails
    if ((buffer = realloc(buffer, size + (1000 * sizeof(long)))) == NULL)
    {
        free(oldbuffer); // free original block
        return 1;
    }
    size = malloc_size(buffer);
    printf("Size of block after realloc of 1000 more longs: %zu\n", size);

    free(buffer);
    return 0;
}