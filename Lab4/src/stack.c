#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"
#include "stack.h"


Stack* createStack(void (*printFunction)(void *toBePrinted),
        void (*deleteFunction)(void *toBeDeleted),
        int (*compareFunction)(const void *first, const void *second)){

    Stack *s = malloc(sizeof(Stack));
    s->count = 0;
    s->list = initializeList(printFunction, deleteFunction, compareFunction);

    return s;
}


void push(Stack *s, void* data){
    insertFront(s->list, data);
    s->count++;
}



void* top(Stack *s){
    if(s == NULL){
        return NULL;
    }

    if(s->list->head != NULL){
        return s->list->head->data;
    }
    return NULL;
}


void pop(Stack *s){
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


int count(Stack *s){
    return s->count;
}


void destroyStack(Stack *s){
    deleteList(s->list);
    s->count = 0;
    free(s);
}