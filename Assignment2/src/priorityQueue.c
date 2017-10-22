#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"


PriorityQueue *createQueue(void (*printFunction) (void * toBePrinted),
    void (*deleteFunction)(void *toBeDeleted), 
    int (*compareFunction)(const void *first, const void *second)){

    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->list = initializeList(printFunction, deleteFunction, compareFunction);
    pq->count = 0;

    return pq;
}


void insert(PriorityQueue *pq, void *data, int priority){
    if(pq == NULL){
        return;
    }
    insertSorted(pq->list, data, priority);
    pq->count++;
}


int queueEmpty(PriorityQueue *pq){
    if(pq != NULL){
        return isEmpty(pq->list);
    }

    return 0;
}


void *pop(PriorityQueue *pq){
    if(pq == NULL){
        return NULL;
    }

    if(!queueEmpty(pq)){
        void *last = peek(pq);
        void *data = deleteNodeFromList(pq->list, last);
        if(data != NULL){
            pq->count--;
        }
        return data;
    }

    return NULL;
}


void *peek(PriorityQueue *pq){
    if(!queueEmpty(pq)){
        return getFromBack(pq->list);
    }
    return NULL;
}


void destroyQueue(PriorityQueue *pq){
    if(pq != NULL){
        if(pq->list != NULL){
            deleteList(pq->list);
        }
        free(pq);
    }
}


int getCount(PriorityQueue *pq){
    return pq->count;
}


void increasePriority(PriorityQueue *pq){
    changePriority(pq->list);
}

