#include <stdlib.h>
#include <stdio.h>


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

#include "list.h"

int main()
{
    node* head;
    head =  createNode("0");
    appendToList(head, "1");
    appendToList(head, "2");
    appendToList(head, "3");
    
    insertInList(head, 2, "X");

    printf("Test: %s\n", getNodeAt(head, 2)->data );

    removeFromList(head, 2);

    printf("Test: %s\n", getNodeAt(head, 2)->data );

    return 0;
}