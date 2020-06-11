#include <stdlib.h>
#include <stdio.h>

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