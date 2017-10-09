/**
* @file stack.h
* @author Abinav Bukkaraya
* @date October 2017
* @brief File containing the function definitions of a stack
*/

#ifndef STACK_H
#define STACK_H
#include "linkedListAPI.h"


typedef struct stack{
    List *list;
    int count;
}Stack;


Stack* createStack(void (*printFunction)(void *toBePrinted),
                    void (*deleteFunction)(void *toBeDeleted),
                    int (*compareFunction)(const void *first, const void *second));

void push(Stack *s, void *data);

void* top(Stack *s);

void pop(Stack *s);

int count(Stack *s);

void destroyStack(Stack *s);

#endif