/**
* @file priorityQueue.h
* @author Abinav Bukkaraya
* @date October 2017
* @brief File containing the function definitions of a priorityQueue
*/
#include "linkedListAPI.h"
#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_


typedef struct PriorityQueue{
    List *list;
    int count;
}PriorityQueue;


/**Function to point the queue to the appropriate functions. Allocates memory to the struct.
*@return pointer to the queue
*@param printFunction function pointer to print a single node of the list
*@param deleteFunction function pointer to delete a single piece of data from the list
*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order
**/
PriorityQueue *createQueue(void (*printFunction) (void * toBePrinted),
void (*deleteFunction)(void *toBeDeleted), 
int (*compareFunction)(const void *first, const void *second));


/** Inserts data inside the queue base on it's priority
*@pre queue exists and has memory allocated to it. Node to be added is valid.
*@post The node to be added will be placed immediately before or after the first occurrence of a related node
*@param pq pointer to the priorityQueue
*@param data a pointer to data that is to be added to the queue
*@param priority the priority value of the data being added
**/
void insert(PriorityQueue *pq, void *data, int priority);

/** Checks if queue is empty or not
*@pre queue exists and has memory allocated to it. Node to be added is valid.
*@param pq pointer to the priorityQueue
*@return 0 if queue is not empty and 1 if queue is empty
**/
int queueEmpty(PriorityQueue *pq);

/** Removes the element at the top of the queue
*@pre queue exists and has memory allocated to it. Node to be added is valid.
*@param pq pointer to the priorityQueue
*@return pointer to the data that was removed from the queue or NULL if queue is empty
**/
void *pop(PriorityQueue *pq);

/** Returns the element sitting at the top of the queue
*@pre queue exists and has memory allocated to it. Node to be added is valid.
*@param pq pointer to the priorityQueue
*@return pointer to data at the top or NULL if the queue is empty
**/
void *peek(PriorityQueue *pq);

/** Destroys the queue and frees all memory
*@pre queue exists and has memory allocated to it. Node to be added is valid.
*@param pq pointer to the priorityQueue
**/
void destroyQueue(PriorityQueue *pq);

/** Returns the number of elements in the queue
*@pre queue exists and has memory allocated to it. Node to be added is valid.
*@param pq pointer to the priorityQueue
@return count int
**/
int getCount(PriorityQueue *pq);

/** Changes the priority of the data inside the queue based on conditions
*@pre queue exists and has memory allocated to it. Node to be added is valid.
*@param pq pointer to the priorityQueue
**/
void increasePriority(PriorityQueue *pq);

#endif