typedef struct Car{
    char dir;
    int arrTime;
    char travelDir;
    struct Car *prev;
    struct Car *next;
} Car;