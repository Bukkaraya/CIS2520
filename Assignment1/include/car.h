#ifndef CAR_H
#define CAR_H


typedef struct Car{
    char dir;
    int arrTime;
    char travelDir;
    double interTime;
    double finishTime;
} Car;


/**Function that returns a dynamically allocated Car struct.
*@param dir char
*@param travelDir char
*@param arrTime int
*@return pointer to Car struct
**/
Car* createCar(char dir, int arrTime, char travelDir);


/**Function that returns the direction of car.
*@param pointer to a Car struct
*@return dir char
**/
char getDirection(Car *c);


/**Function that returns the arrival time.
*@param pointer to a Car struct
*@return arrTime char
**/
int getArrivalTime(Car *c);


/**Function that returns the travelDirection.
*@param pointer to a Car struct
*@return travelDir char
**/
char getTravelDirection(Car *c);


/**Function to set the finish time.
*@param pointer to a Car struct
*@param finishTime double
**/
void setFinishTime(Car *c, double finishTime);


/**
*Comparison for two pointers to generic data. Must define an element of these pointers to use to compare
*the two pointers with each other.
*@pre first and second must be comparable.
*@param first pointer to data to be compared with second.
*@param second pointer to data to be compared with first.
*@return for sorting purposes,
*<0 The element pointed by 'first' goes before the element pointed by 'second'
*0  The element pointed by 'first' is equivalent to the element pointed by 'second'
*>0 The element pointed by 'first' goes after the element pointed by 'second'
**/
int compareCars(const void *first, const void *second);


/**Print Function for the car
*@pre Data must be able to be printed via a standard print function
*@param toBePrinted pointer to the data that is to be printed. Taken from a data structure.
**/
void printCar(void *toBePrinted);


/**Function to delete linked list node based on the incoming data.
*@pre Data must not already be freed or NULL
*@param toBeDeleted Pointer to generic data to be deleted in the list.
**/
void deleteCar(void *toBeDeleted);


/**Function to set the intersection arrival time.
*@param pointer to a Car struct
*@param interTime double
**/
void setInterTime(Car *c, double interTime);


#endif