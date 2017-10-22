#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

void printInt(void *data);
void deleteInt(void *data);
int compareInt(const void *first, const void *second);
void printTestInfo(int n, char *info);
int printPassFail(int b);


int main(int argc, char **argv){
    printf("Running test program.\n\n");
    int numTests = 0;
    int testsPassed = 0;
    int *n1 = malloc(sizeof(int));
    int *n3 = malloc(sizeof(int));
    *n1 = 5;
    *n3 = 8;
    
    //Test to make sure the queue is intialized
    printTestInfo(++numTests, "Testing to make sure the priority queue has been intialized.");
    PriorityQueue *pq = createQueue(printInt, deleteInt, compareInt);
    printf("Expected: 1\n");
    printf("Received: %d\n", pq != NULL);
    testsPassed += printPassFail(pq != NULL);

    //Test to make sure queueEmpty function returns the right value
    printTestInfo(++numTests, "Testing the queueEmpty function on an empty list.");
    printf("Expected: 1\n");
    printf("Received: %d\n", queueEmpty(pq) == 1);
    testsPassed += printPassFail(queueEmpty(pq) == 1);

    //Testing to make sure a value of null is returned when you pop from an empty queue
    printTestInfo(++numTests, "Testing to make sure NULL is returned when retrieving the top element in an empty queue.");
    printf("Expected: 1\n");
    void *data = peek(pq);
    printf("Received: %d\n", data == NULL);
    testsPassed += printPassFail(data == NULL);

    printTestInfo(++numTests, "Testing to make sure element is added to an empty queue.");
    printf("Expected: 5\n");
    insert(pq, n1, 3);
    int *n2 = (int *) peek(pq);
    printf("Received: %d\n", *n2);
    testsPassed += printPassFail(*n2 == 5);

    printTestInfo(++numTests, "Testing to make element is added in the right position when adding to a queue.");
    printf("Expected:\n5\n8\n");
    printf("Received:\n");
    insert(pq, n3, 1);
    printForward(pq->list);
    testsPassed += printPassFail(getCount(pq) == 2);

    printTestInfo(++numTests, "Testing to make sure element is properly popped from the queue.");
    printf("Expected:\n5\n");
    pop(pq);
    printf("Received:\n");
    printForward(pq->list);
    testsPassed += printPassFail(getCount(pq) == 1);

    //Running test program with valgrind will indicate that all memory has been freed
    printTestInfo(++numTests, "Testing to make sure the queue is completely deleted.");
    destroyQueue(pq);
    pq = NULL;
    printf("Expected: 1\n");
    printf("Received: %d\n", pq == NULL);
    testsPassed += printPassFail(pq == NULL);

    
    free(n3);

    printf("%d of %d tests passed.\n", testsPassed, numTests);
    
    return 0;
}





void printInt(void *data){
    int *n = (int *) data;
    printf("%d\n", *n);
}


void deleteInt(void *data){
    if(data != NULL){
        free(data);
    }
}


int compareInt(const void *first, const void *second){
    int *n1 = (int *) first;
    int *n2 = (int *) second;

    if(*n1 > *n2){
        return 1;
    }else if(*n1 < *n2){
        return -1;
    }else{
        return 0;
    }

}


void printTestInfo(int n, char *info){
    printf("Test #%d: %s\n", n, info);
}


int printPassFail(int b){
    if(b == 0){
        printf("FAIL\n\n");
        return 0;
    }else{
        printf("PASS\n\n");
        return 1;
    }
}
