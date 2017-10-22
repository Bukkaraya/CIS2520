#include "linkedListAPI.h"
#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_


typedef struct PriorityQueue{
    List *list;
    int count;
}PriorityQueue;

PriorityQueue *createQueue(void (*printFunction) (void * toBePrinted),
void (*deleteFunction)(void *toBeDeleted), 
int (*compareFunction)(const void *first, const void *second));

void insert(PriorityQueue *pq, void *data, int priority);

int queueEmpty(PriorityQueue *pq);

void pop(PriorityQueue *pq);

void *peek(PriorityQueue *pq);

void destroyQueue(PriorityQueue *pq);

#endif