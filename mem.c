#include <stdlib.h>


void* debugMalloc(size_t size, char* file, int line)
{
    printf("%s:%d allocated %d bytes\n", file, line, size);
    return __malloc(size);
}

void* debugRealloc(void* ptr, size_t size, char* file, int line)
{
    printf("%s:%d relocated %d bytes\n", file, line, size);
    return __realloc(ptr, size);
}

void debugFree(void* ptr, char* file, int line)
{
    printf("%s:%d freeed %d bytes\n", file, line, ptr);
    __free(ptr);
}

#define malloc(n) debugMalloc(n, __FILE__, __LINE__) /* Replaces malloc. */
#define realloc(n, m) debugRealloc(n, m, __FILE__, __LINE__) /* Replaces realloc. */
#define free(n) debugFree(n, __FILE__, __LINE__) /* Replaces free. */
