#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"
#include "stack.h"

/**Function to dynamically allocated a stack
*@return pointer to the stack
*@param printFunction function pointer to print a single node of the stack
*@param deleteFunction function pointer to delete a single piece of data from the stack
*@param compareFunction function pointer to compare two nodes of the stack in order to test for equality or order
**/
Stack* createStack(void (*printFunction)(void *toBePrinted),
        void (*deleteFunction)(void *toBeDeleted),
        int (*compareFunction)(const void *first, const void *second)){

    Stack *s = malloc(sizeof(Stack));
    s->count = 0;
    s->list = initializeList(printFunction, deleteFunction, compareFunction);

    return s;
}

/**Inserts the given data to the top of the stack
*@pre 'Stack' must exist
*@param Stack *s pointer to the stack
*@param data a void pointer that is added to the stack
**/
void push(Stack *s, void* data){
    insertFront(s->list, data);
    s->count++;
}


/**Function to return the data at the top of the stack
*@pre The list exists and has memory allocated to it
*@param Stack *s pointer to the stack
*@return pointer to the data located at the top of the stack, returns null if stack is null
**/
void* top(Stack *s){
    if(s == NULL){
        return NULL;
    }

    if(s->list->head != NULL){
        return s->list->head->data;
    }
    return NULL;
}

/**Function to remove the top element in the stack
*@pre The stack exists and has memory allocated to it
*@param Stack *s pointer to the stack
**/
void pop(Stack *s){
    if(s == NULL){
        return;
    }

    if(s->list->head != NULL){
        void* toBeDeleted = top(s);   
        int result = deleteNodeFromList(s->list, toBeDeleted);
        if(result == EXIT_SUCCESS){
            s->count--;
        }
    }else{
        printf("Stack is empty!\n");
    }
}

/**Function to return the number of items in the stack
*@pre The stack exists and has memory allocated to it
*@param Stack *s pointer to the stack
*@return int the number of elements in the stack
**/
int count(Stack *s){
    if(s == NULL){
        return -1;
    }
    return s->count;
}

/** Deletes the entire stack
*@pre 'Stack' type must exist
*@param stack pointer stack
**/
void destroyStack(Stack *s){
    
    if(s == NULL){
        return;
    }

    deleteList(s->list);
    s->count = 0;
    free(s);
}