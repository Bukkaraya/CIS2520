typedef struct traveldata{
    char dir;
    int arrTime;
    char travelDir;
} TravelData;

typedef struct Car{
    void *data;
    struct Car *next;
    struct Car *prev;
} Car;

typedef struct Traffic{
    Car *head;
    int length;
    void (*destroyPtr) (void*);
} Traffic;

void destroy(void* data);
Traffic* createTraffic(void (* dPtr)(void *));
TravelData* createData(char dir, int arrTime, char travelDir);
Car* createCar(TravelData *t);
void destroyTraffic(Traffic *t);
