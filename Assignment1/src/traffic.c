#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "traffic.h"


//Function to destroy the list
void destroy(void* data){
    if(data != NULL){
        free(data);
        data = NULL;
    }
}


//Function to create a struct TravelData
TravelData* createData(char dir, int arrTime, char travelDir){
    TravelData *t = malloc(sizeof(TravelData));
    if(t != NULL){
        t->arrTime = arrTime;
        t->dir = dir;
        t->travelDir = travelDir;
    }
    return t;
}


//Function to create a struct Car (Node)
Car* createCar(TravelData *t){
    Car *c = malloc(sizeof(Car));
    if(c != NULL){
        c->data = t;
        c->next = NULL;
        c->prev = NULL;
    }
    return c;
}

//Function to create the Traffic List
Traffic* createTraffic(void (* dPtr)(void *)){
    Traffic *traffic = malloc(sizeof(Traffic));
    if(traffic != NULL){
        traffic->length = 0;
        traffic->head = createCar(NULL);
        traffic->destroyPtr = dPtr;
    }
    return traffic;
}

//Function to destroy a list
void destroyTraffic(Traffic *t){
    Car *temp = NULL;
    Car *curr = t->head;
    while(curr != NULL){
        temp = curr->next;
        t->destroyPtr(curr->data);
        free(curr);
        curr = temp;
    }
    t->head = curr;
    t->length = 0;
}

//Function to insert at head

/*
Function to insert at head
Function to get first element
Function to delete first element
Function to find length of list
Function to get an element of the list
Function to print a list in the required format
Function to add to end of list*
Function to delete end*
Function to remove a specific node*

*/