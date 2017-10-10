#include <stdio.h>
#include <stdlib.h>
#include "car.h"

Car* createCar(char dir, int arrTime, char travelDir){
    Car *c = malloc(sizeof(Car));
    if (c != NULL) {
        c->dir = dir;
        c->arrTime = arrTime;
        c->travelDir = travelDir;
        c->interTime = 0;
        c->finishTime = 0;

        return c;
    }
    
    return NULL;
}


char getDirection(Car *c){ 
    return c->dir; 
}


int getArrivalTime(Car *c){ 
    return c->arrTime; 
}


char getTravelDirection(Car *c){ 
    return c->travelDir; 
}


void setFinishTime(Car *c, double finishTime){
    c->finishTime = finishTime;
} 


void setInterTime(Car *c, double interTime){
    c->interTime = interTime;
}


int compareCars(const void *first, const void *second){
    Car *c1 = (Car *) first;
    Car *c2 = (Car *) second;
    if (c1->arrTime > c2->arrTime) {
        return 1;
    } else if (c1->arrTime < c2->arrTime) {
        return -1;
    } else {
        return 0;
    }
}

void printCar(void *toBePrinted){
    Car *c = (Car *) toBePrinted;

    printf("%c %d %c\t\t%g\t%g\n", c->dir, c->arrTime, c->travelDir, c->interTime, c->finishTime);
}


void deleteCar(void *toBeDeleted){
    if(toBeDeleted != NULL){
        free(toBeDeleted);
        toBeDeleted = NULL;
    }
}