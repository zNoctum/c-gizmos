#include <stdlib.h>
#include <stdio.h>

#ifndef __MEM_H__
#define __MEM_H__
#ifdef __cplusplus
extern "C" {
#endif

void* debugMalloc(size_t size, char* file, int line)
{
    printf("%s:%d allocated %d bytes\n", file, line, size);
    return malloc(size);
}

void debugFree(void* ptr, char* file, int line)
{
    printf("%s:%d freeed %d bytes\n", file, line, sizeof(ptr));
    free(ptr);
}

#define malloc(x) debugMalloc(x, __FILE__, __LINE__)
#define free(x) debugFree(x, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif
#endif