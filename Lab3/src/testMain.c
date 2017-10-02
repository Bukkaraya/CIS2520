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

    int *i1 = malloc(sizeof(int));
    *i1 = 42;
    int *i3 = malloc(sizeof(int));
    *i3 = 54;
    int *i2 = malloc(sizeof(int));
    *i2 = 7;
    Book *b1 = createBook("Harry Potter", 4.00);
    Book *b3 = createBook("One Piece", 4.99);
    Book *b2 = createBook("Naruto", 7.99);
    Book *b4 = createBook("Lord of the Rings", 24.99);
    Book *b5 = NULL;

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

    //Test for insertBack
    printTestInfo(++numTests, "Testing to make sure Book is added to the back of the list.");
    printf("Expected: \nHarry Potter : 4.000\nOne Piece : 4.990\n");
    insertBack(l1, b3);
    printf("Recieved: \n");
    printForward(l1);
    testsPassed += printPassFail(l1->head->next != NULL);

    printTestInfo(++numTests, "Testing to make sure int is added to the back of the list.");
    printf("Expected: \n42 \n54\n");
    insertBack(l2, i3);
    printf("Recieved: \n");
    printForward(l2);
    testsPassed += printPassFail(l2->head->next != NULL);

    //Test for insertSorted Function
    printTestInfo(++numTests, "Testing to make sure Book is added properly to the sorted list.");
    printf("Expected:\n");
    printf("Harry Potter : 4.000\n");
    printf("Naruto : 4.990\n");
    printf("One Piece : 4.990\n");
    insertSorted(l1, b2);
    printf("Recieved:\n");
    printForward(l1);
    testsPassed += printPassFail(getPrice((Book *) getFromBack(l1)) == 7.99);

    printTestInfo(++numTests, "Testing to make sure int is added properly in the sorted list");
    printf("Expected: \n7\n42\n54\n");
    insertSorted(l2, i2);
    printf("Recieved:\n");
    printForward(l2);
    testsPassed += printPassFail(*(int *)getFromFront(l2) == 7);


    //Test for getFromFront
    printTestInfo(++numTests, "Testing to make sure the first element in the list is retrieved.");
    printf("Expected:\nHarry Potter : 4.000\n");
    data = getFromFront(l1);
    printf("Recieved:\n");
    printBook(data);
    testsPassed += printPassFail(getPrice((Book *) data) == 4.000);

    printTestInfo(++numTests, "Testing to make sure the first element in the list is retrieved.");
    printf("Expected:\n7\n");
    data = getFromFront(l2);
    printf("Recieved:\n");
    printInt(data);
    testsPassed += printPassFail(*(int *)data == 7);

    //Test for getFromBack
    printTestInfo(++numTests, "Testing to make sure the last element in the list is retrieved.");
    printf("Expected:\nNaruto : 7.990\n");
    data = getFromBack(l1);
    printf("Recieved:\n");
    printBook(data);
    testsPassed += printPassFail(getPrice((Book *) data) == 7.990);

    printTestInfo(++numTests, "Testing to make sure the last element in the list is retrieved.");
    printf("Expected:\n54\n");
    data = getFromBack(l2);
    printf("Recieved:\n");
    printInt(data);
    testsPassed += printPassFail(*(int *)data == 54);

    //Test to delete a node from the list
    printTestInfo(++numTests, 
        "Test to make sure nothing is deleted when trying to delete a Book element that is not present in the list.");
    printf("Expected:\nMatch not found.\n");
    printf("Recieved:\n");
    int result = deleteNodeFromList(l1, b4);
    testsPassed += printPassFail(result == -1);

    printTestInfo(++numTests, 
        "Test to make sure required element is deleted from list.");
    printf("Expected:\n42\n54\n");
    printf("Recieved:\n");
    result = deleteNodeFromList(l2, i2);
    printForward(l2);
    testsPassed += printPassFail(result == EXIT_SUCCESS);
    
    //Test to make sure list is completely deleted
    printTestInfo(++numTests, "Test to make sure linked list containing Book struct is deleted.");
    printf("Expected: 1\n");
    deleteList(l1);
    l1 = NULL;
    printf("Recieved: %d", l1 == NULL);
    testsPassed += printPassFail(l1 == NULL);

    //Test to make sure list is completely deleted
    printTestInfo(++numTests, "Test to make sure linked list containing Book struct is deleted.");
    printf("Expected: 1\n");
    deleteList(l2);
    l2 = NULL;
    printf("Recieved: %d\n", l2 == NULL);
    testsPassed += printPassFail(l2 == NULL);

    


    free(b4);
    b4 = NULL;

    

    printf("%d tests passed out of %d tests.\n", testsPassed, numTests);
    return 0;
}