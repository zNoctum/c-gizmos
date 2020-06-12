#include <stdlib.h>

#ifndef __LIST_H__
#define __LIST_H__
#ifdef __cplusplus
extern "C" {
#endif

typedef struct node node;

/**
 * Function to create new node struct.
 * 
 * @return node* - Returns blank node.
 */
extern node* createNode(void* data);

/**
 * Function to get a node at a index.
 * 
 * @param node* head - Pointer to first element in a list.
 * @param int index - Index of item in linked list.
 * 
 * @return node* - Returns ponter to selected node or NULL on error.
 */
node* getNodeAt(node* head, int index);

/**
 * Function to get a node at a index.
 * 
 * @param node* head - Pointer to first element in a list.
 * @param int index - Index of item in linked list.
 * 
 * @return void* - Returns ponter to selected node or NULL on error.
 */
void* getDataAt(node* head, int index);

/**
 * Function to append to linked list
 * 
 * @param node* head - Pointer to the first element in a list.
 * @param void* data - Pointer to the node which should be appended
 */
void appendToList(node* head, void* data);

/**
 * Function to insert in linked list
 * 
 * @param node* head - Pointer to the first element in a list.
 * @param int index - Index of item in linked list.
 * @param void* data - Pointer to the data which should be appended
 */
void insertInList(node* head, int index, void* data);

/**
 * Function to remove a element of a linkd list
 * 
 * @param node* head - Pointer to the first element in a list.
 * @param int index - Index of item in linked list.
 */
extern void removeFromList(node* head, int index);

#ifdef __cplusplus
}
#endif
#endif