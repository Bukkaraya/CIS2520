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
    printTestInfo(++testNumber, "Testing the proper \
                creation of TravelData struct");
    printf("Expected: %c, %d, %c \n", 'N', 10, 'F');
    printf("Received: %c, %d, %c \n", t->dir, t->arrTime, t->travelDir);
    testsPassed += printPassFail(t != NULL);
    free(t);
    t = NULL;
    
    //Testing proper creation of Car struct
    t = createData('W', 5, 'L');
    Car *c = createCar(t);
    printTestInfo(++testNumber, "Testing the proper creation of struct Car");
    printf("Expected: %d\n", 1);
    printf("Received: %d\n", (c != NULL));
    testsPassed += printPassFail(c != NULL);
    free(t);
    free(c);
    t = NULL;
    c = NULL;

    //Testing proper creation of struct Traffic
    Traffic *traffic = createTraffic(destroy);
    printTestInfo(++testNumber, "Testing the proper \
                creation of struct Traffic");
    printf("Expected: %d %d\n", 0, 1);
    printf("Received: %d %d\n", traffic->length, traffic->head != NULL);
    testsPassed += printPassFail(traffic != NULL);
    free(traffic->head);
    free(traffic);
    traffic = NULL;
    
    //Making sure the destroy function completely destroys the list
    traffic = createTraffic(destroy);
    printTestInfo(++testNumber, "Testing the proper \
                destruction of the struct Traffic");
    destroyTraffic(traffic);
    printf("Expected: %d\n", 0);
    printf("Received: %d\n", !(traffic->head == NULL));
    testsPassed += printPassFail(traffic->head == NULL);
    free(traffic);
    traffic = NULL;

    //Testing to check if element is added to the beginning of the struct
    t = createData('E', 14, 'R');
    c = createCar(t);
    traffic = createTraffic(destroy);
    printTestInfo(++testNumber, "Testing to make sure \
                element is added to head of the list");
    traffic->head = insertFirst(traffic->head, c);
    printf("Expected: %d\n", 1);
    printf("Received: %d\n", traffic->head->next != NULL);
    testsPassed += printPassFail(traffic->head->next != NULL);
    destroyTraffic(traffic);
    free(traffic);
    traffic = NULL;
    c = NULL;
    t = NULL;


    //Test to delete the first element in the list
    t = createData('N', 23, 'F');
    c = createCar(t);
    traffic = createTraffic(destroy);
    traffic->head = insertFirst(traffic->head, c);
    printTestInfo(++testNumber, "Testing to make sure the first \
                element in the list is deleted");
    traffic->head = deleteFirst(traffic->head);
    printf("Expected: %d\n", 1);
    printf("Received: %d\n", 
        traffic->head->next == NULL && traffic->head->prev == NULL);
    testsPassed += printPassFail(
        traffic->head->next == NULL && traffic->head->prev == NULL);
    destroyTraffic(traffic);
    free(traffic);
    traffic = NULL;
    t = NULL;
    c = NULL;

    //Test to make sure function returns right length
    t = createData('S', 3, 'L');
    c = createCar(t);
    TravelData* t2 = createData('N', 12, 'R');
    Car* c2 = createCar(t2);
    traffic = createTraffic(destroy);
    traffic->head = insertFirst(traffic->head, c);
    traffic->head = insertFirst(traffic->head, c2);
    printTestInfo(++testNumber, "Testing to make sure function \
                returns the right length of the list");
    int len = getListLength(traffic->head);
    printf("Expected: %d\n", 3);
    printf("Recieved: %d\n", len);
    testsPassed += printPassFail(len == 3);
    destroyTraffic(traffic);
    free(traffic);
    traffic = NULL;
    t = NULL;
    c = NULL;
    t2 = NULL;
    c2 = NULL;
    

    printf("Number of Tests: %d\n", testNumber);
    printf("Number of Tests Passed: %d\n", testsPassed);

    return 0;
}