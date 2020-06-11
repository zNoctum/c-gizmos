#include "list.h"

node* createNode(void* data)
{
    node* tmp;
    
    tmp = (node*) malloc(sizeof(node));
    tmp->next = NULL;
    tmp->data = data;

    return tmp;
}

node* getNodeAt(node* head, int index)
{
    node* curNode;
    int curNodeIndex;

    curNode = head;
    curNodeIndex = 0;

    while(curNode != NULL)
    {
        if(curNodeIndex <= index)
        {
            if(curNodeIndex == index)
            {
                return curNode;
            }
        } else
        {
            return NULL;
        }
        
        curNodeIndex++;
        curNode = curNode->next;
    }
}

void* getDataAt(node* head, int index)
{
    return getNodeAt(head, index)->data;
}

void appendToList(node* head, void* data)
{
    node* curNode;

    curNode = head;

    while (curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    curNode->next = createNode(data);
}

void insertInList(node* head, int index, void* data)
{
    node* tmpHead;
    node* tmpTail;
    node* toInsert;

    tmpHead = getNodeAt(head, index - 1);
    tmpTail = tmpHead->next;
    toInsert = createNode(data);

    tmpHead->next = toInsert;
    toInsert->next = tmpTail;
}

void removeFromList(node* head, int index)
{
    node* tmpHead;
    node* tmpTail;

    if(!index)
    {
        tmpTail = head->next;
        head->data = tmpTail->data;
        head->next = head->next->next;

        free(tmpTail);
        return;
    }
    
    tmpHead = getNodeAt(head, index - 1);
    tmpTail = tmpHead->next->next;

    tmpHead->next = tmpTail;
}

