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
        traffic->length = 1;
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
Car* insertFirst(Car *head, Car* c){
    c->next = head;
    head-> prev = c;
    head = c;
    return head;
}

//Function to delete the first element
Car* deleteFirst(Car *head){
    Car *temp = head->next;
    free(head->data);
    free(head);
    head = temp;
    head->prev = NULL;
    return head;
}

//Function to find length of the Cars list
int getListLength(Car* head){
    int len = 0;
    Car *cur = head;
    while(cur != NULL){
        len++;
        cur = cur->next;
    }
    return len;
}

//Function to print a list data in required format
void printList(Car* head){
    Car *cur = head;
    while(cur != NULL){
        if(cur->data != NULL){
            TravelData *t = (TravelData *) cur->data;
            printf("%c\t%d\t%c\n", t->dir, t->arrTime, t->travelDir);
        }
        cur = cur->next;
    }
}