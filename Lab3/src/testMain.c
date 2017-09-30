#include <stdio.h>
#include <stdlib.h>
#include "book.h"
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
    int *number = (int *) num;
    printf("%d\n", *number);
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

    int *i1 = malloc(sizeof(int));
    *i1 = 42;
    int *i3 = malloc(sizeof(int));
    *i3 = 54;
    Book *b1 = createBook("Harry Potter", 4.00);
    Book *b3 = createBook("One Piece", 4.99);

    //Test function for initializeList
    List *l1 = initializeList(printBook, deleteListNode, compareBook);
    printTestInfo(++numTests, "Testing to check proper initialization of List with functions related to Book struct");
    printf("Expected: %d\n", 1);
    printf("Recieved: %d\n", l1 != NULL);
    testsPassed += printPassFail( l1 != NULL);

    List *l2 = initializeList(printInt, deleteListNode, compareInt);
    printTestInfo(++numTests, "Testing to check proper initialization of List with functions related to integer");
    printf("Expected: %d\n", 1);
    printf("Recieved: %d\n", l2 != NULL);
    testsPassed += printPassFail( l2 != NULL);

    //Test initializeNode function
    Node *n1 = initializeNode(b3);
    printTestInfo(++numTests, "Testing to check proper initialization of Node with a Book struct");
    printf("Expected: %d\n", 1);
    printf("Recieved: %d\n", n1 != NULL);
    testsPassed += printPassFail( n1 != NULL);

    Node *n2 = initializeNode(i3);
    printTestInfo(++numTests, "Testing to check proper initialization of Node with an integer");
    printf("Expected: %d\n", 1);
    printf("Recieved: %d\n", n2 != NULL);
    testsPassed += printPassFail( n2 != NULL);

    //Tests for insertFront
    printTestInfo(++numTests, "Testing to make sure Book is added to the front of the list");
    printf("Expected: %s\n", "Harry Potter : 4.000");
    insertFront(l1, b1);
    printf("Recieved: ");
    printForward(l1);
    testsPassed += printPassFail(l1->head != NULL);

    printTestInfo(++numTests, "Testing to make sure Book is added to the front of the list");
    printf("Expected: %s\n", "42");
    insertFront(l2, i1);
    printf("Recieved: ");
    printForward(l2);
    testsPassed += printPassFail(l2->head != NULL);
    
    

    printf("%d tests passed out of %d tests.\n", testsPassed, numTests);
    return 0;
}