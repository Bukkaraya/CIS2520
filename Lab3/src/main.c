#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"
#include "book.h"

void deleteListNode(void *toBeDeleted){
    if(toBeDeleted != NULL){
        free(toBeDeleted);
        toBeDeleted = NULL;
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

int main(void){

    List *list = initializeList(printBook, deleteListNode, compareBook);

    Book *b1 = createBook("Harry Potter", 4.00);
    Book *b2 = createBook("One Piece", 4.99);
    Book *b3 = createBook("Eye of the World", 8.99);
    int *n1 = malloc(sizeof(int));
    *n1 = 51;
    int *n2 = malloc(sizeof(int));
    *n2 = 83;
    int *n3 = malloc(sizeof(int));
    *n3 = 7;

    List *intList = initializeList(printInt, deleteListNode, compareInt);

    printf("List 1:\n");
    insertFront(list, b1);
    insertFront(list, b2);
    insertBack(list, b3);
    printForward(list);

    printf("----------\nList 2:\n");
    insertSorted(intList, n1);
    insertSorted(intList, n2);
    insertSorted(intList, n3);
    printForward(intList);




    return 0;
}