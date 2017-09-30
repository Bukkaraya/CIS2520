#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"

int dummyCompare(const void *first, const void *second){
    return 0;
}

void dummyPrint(void *toBePrinted){
    printf("Hello");
}

int main(void){
    
    List *l = initializeList(dummyPrint, dummyPrint, dummyCompare);
    printForward(l);
    free(l)

    return 0;
}