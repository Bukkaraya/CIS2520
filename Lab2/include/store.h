#ifndef STORE_H
#define STORE_H

/**
 * Stores information related to the store
*/
typedef struct Store{
    void *item;
    void (*printFunction) (void* data);
} Store;


/**
 *[createStore description]
 @param item void pointer either book or boardgame struct
 @param fPtr function pointer related to the print function of item
 @return dynamically created Store
**/
Store* createStore(void* item, void (*fPtr) (void* data));

/**
 * Changes item in store and print function related to item
 @param item void pointer either book or boardgame struct
 @param fPtr function pointer related to the print function of item
**/
void changeStoreItem(Store* s, void* item, void (*fPtr) (void* data));

/**
 * Print the information related to item in store
 @param item s [Store]
**/
void displayStore(Store* s);

#endif