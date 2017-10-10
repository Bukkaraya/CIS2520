#ifndef CAR_H
#define CAR_H


typedef struct Car{
    char dir;
    int arrTime;
    char travelDir;
    double interTime;
    double finishTime;
} Car;


Car* createCar(char dir, int arrTime, char travelDir);

char getDirection(Car *c);

int getArrivalTime(Car *c);

char getTravelDirection(Car *c);

void setFinishTime(Car *c, double finishTime);

int compareCars(const void *first, const void *second);

void printCar(void *toBePrinted);

void deleteCar(void *toBeDeleted);

void setInterTime(Car *c, double interTime);

#endif