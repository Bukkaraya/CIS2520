#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "traffic.h"

void printTestInfo(int n, char *info){
    printf("Test #%d: %s\n", n, info);
}

int printPassFail(int b){
    if(b == 0){
        printf("FAIL\n\n");
        return 0;
    }else{
        printf("PASS\n\n");
        return 1;
    }
}

int main(int argc, char ** argv){
    int testNumber = 0;
    int testsPassed = 0;
    printf("Starting the test program\n\n");
    
    //Test for function createData
    TravelData *t = NULL;
    t = createData('N', 10, 'F');
    printTestInfo(++testNumber, "Testing the proper creation of TravelData struct.");
    printf("Expected: %c, %d, %c \n", 'N', 10, 'F');
    printf("Recieved: %c, %d, %c \n", t->dir, t->arrTime, t->travelDir);
    testsPassed += printPassFail(t != NULL);
    free(t);
    t = NULL;
    
    //Testing proper creation of Car struct
    t = createData('W', 5, 'L');
    Car *c = createCar(t);
    printTestInfo(++testNumber, "Testing the proper creation of struct Car");
    printf("Expected: %d\n", 1);
    printf("Recieved: %d\n", (c != NULL));
    testsPassed += printPassFail(c != NULL);
    free(t);
    free(c);
    t = NULL;
    c = NULL;

    //Testing proper creation of struct Traffic
    Traffic *traffic = createTraffic(destroy);
    printTestInfo(++testNumber, "Testing the proper creation of struct Traffic");
    printf("Expected: %d %d\n", 0, 1);
    printf("Recieved: %d %d\n", traffic->length, traffic->head != NULL);
    testsPassed += printPassFail(traffic != NULL);
    free(traffic->head);
    free(traffic);
    traffic = NULL;
    
    //Making sure the destroy function completely destroys the list
    traffic = createTraffic(destroy);
    printTestInfo(++testNumber, "Testing the proper destruction of the struct Traffic");
    destroyTraffic(traffic);
    printf("Expected: %d\n", 0);
    printf("Recieved: %d\n", !(traffic->head == NULL));
    testsPassed += printPassFail(traffic->head == NULL);
    free(traffic);
    traffic = NULL;

    printf("\nNumber of Tests: %d\n", testNumber);
    printf("Number of Tests Passed: %d\n", testsPassed);

    return 0;
}