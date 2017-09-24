#include <stdio.h>
#include <stdlib.h>
#include "store.h"

/*
 *[createStore description]
 @param item void pointer either book or boardgame struct
 @param fPtr function pointer related to the print function of item
 @return dynamically created Store
*/
Store* createStore(void* item, void (*fPtr) (void* data)){
    Store *s = malloc(sizeof(Store));
    s->item = item;
    s->printFunction = fPtr;
    return s;
}

/*
 * Changes item in store and print function related to item
 @param item void pointer either book or boardgame struct
 @param fPtr function pointer related to the print function of item
*/
void changeStoreItem(Store* s, void* item, void (*fPtr) (void* data)){
    s->item = item;
    s->printFunction = fPtr;
}

/*
 * Print the information related to item in store
 @param item s [Store]
*/
void displayStore(Store* s){
    s->printFunction(s->item);
}