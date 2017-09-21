#include <stdio.h>
#include <stdlib.h>
#include "store.h"

Store* createStore(void* item, void (*fPtr) (void* data)){
    Store *s = malloc(sizeof(Store));
    s->item = item;
    s->printFunction = fPtr;
    return s;
}

void changeStoreItem(Store* s, void* item, void (*fPtr) (void* data)){
    s->item = item;
    s->printFunction = fPtr;
}

void displayStore(Store* s){
    s->printFunction(s->item);
}