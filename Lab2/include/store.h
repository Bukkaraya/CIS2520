typedef struct Store{
    void *item;
    void (*printFunction) (void* data);
} Store;

Store* createStore(void* item, void (*fPtr) (void* data));
void changeStoreItem(Store* s, void* item, void (*fPtr) (void* data));
void displayStore(Store* s);