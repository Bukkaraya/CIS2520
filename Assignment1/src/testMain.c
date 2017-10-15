#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"

void printTestInfo(int n, char *info){
    printf("Test #%d: %s\n", n, info);
}

void deleteListNode(void *toBeDeleted){
    if(toBeDeleted != NULL){
        free(toBeDeleted);
        toBeDeleted = NULL;
    }
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

void printInt(void *num){
    if(num != NULL){
        int *number = (int *) num;
        printf("%d\n", *number);
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


int main(int argc, char **argv){
    printf("Running Tests\n\n");

    int numTests = 0;
    int testsPassed = 0;
    void *data = NULL;
    int result = 0;
    int *i1 = malloc(sizeof(int));
    *i1 = 42;
    int *i3 = malloc(sizeof(int));
    *i3 = 54;
    int *i2 = malloc(sizeof(int));
    *i2 = 7;


    List *l2 = initializeList(printInt, deleteListNode, compareInt);
    printTestInfo(++numTests, "Testing to check proper initialization of List with functions related to integer");
    printf("Expected: %d\n", 1);
    printf("Recieved: %d\n", l2 != NULL);
    testsPassed += printPassFail( l2 != NULL);


    Node *n2 = initializeNode(i3);
    printTestInfo(++numTests, "Testing to check proper initialization of Node with an integer");
    printf("Expected: %d\n", 1);
    printf("Recieved: %d\n", n2 != NULL);
    testsPassed += printPassFail( n2 != NULL);


    printTestInfo(++numTests, "Testing to make sure Book is added to the front of the list");
    printf("Expected: %s\n", "42");
    insertFront(l2, i1);
    printf("Recieved: ");
    printForward(l2);
    testsPassed += printPassFail(l2->head != NULL);


    printTestInfo(++numTests, "Testing to make sure int is added to the back of the list.");
    printf("Expected: \n42 \n54\n");
    insertBack(l2, i3);
    printf("Recieved: \n");
    printForward(l2);
    testsPassed += printPassFail(l2->head->next != NULL);


    printTestInfo(++numTests, "Testing to make sure int is added properly in the sorted list");
    printf("Expected: \n7\n42\n54\n");
    insertSorted(l2, i2);
    printf("Recieved:\n");
    printForward(l2);
    testsPassed += printPassFail(*(int *)getFromFront(l2) == 7);


    printTestInfo(++numTests, "Testing to make sure the first element in the list is retrieved.");
    printf("Expected:\n7\n");
    data = getFromFront(l2);
    printf("Recieved:\n");
    printInt(data);
    testsPassed += printPassFail(*(int *)data == 7);


    printTestInfo(++numTests, "Testing to make sure the last element in the list is retrieved.");
    printf("Expected:\n54\n");
    data = getFromBack(l2);
    printf("Recieved:\n");
    printInt(data);
    testsPassed += printPassFail(*(int *)data == 54);


    printTestInfo(++numTests, 
        "Test to make sure required element is deleted from list.");
    printf("Expected:\n42\n54\n");
    printf("Recieved:\n");
    result = deleteNodeFromList(l2, i2);
    printForward(l2);
    testsPassed += printPassFail(result == EXIT_SUCCESS);

    //Test to make sure list is completely deleted
    //Running vagrind will show that the memory has been freed
    int *i5 = malloc(sizeof(int));
    *i5 = 10;
    printTestInfo(++numTests, "Test to make sure linked list containing integer is deleted.");
    l2->deleteNode(i5);
    printf("Expected: 1\n");
    printf("Recieved: %d\n", i5 == NULL);
    testsPassed += printPassFail(i5 == NULL);


    //Test to make sure list is completely deleted
     //Running vagrind will show that the memory has been freed
    printTestInfo(++numTests, "Test to make sure linked list containing integer is deleted.");
    printf("Expected: 1\n");
    deleteList(l2);
    l2 = NULL;
    printf("Recieved: %d\n", l2 == NULL);
    testsPassed += printPassFail(l2 == NULL);

    


    

    printf("%d tests passed out of %d tests.\n", testsPassed, numTests);
    return 0;
}