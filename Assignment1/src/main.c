#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "linkedListAPI.h"
#include "car.h"
#define MAX_LEN 150

void removeNewLineChar(char *str);
void popFront(List *list);


int main(int argc, char ** argv){
    printf("Starting Main Program\n");
    char fileName[MAX_LEN];
    FILE *inputFile = NULL;
    char values[MAX_LEN];
    List *north = initializeList(printCar, deleteCar, compareCars);
    List *east = initializeList(printCar, deleteCar, compareCars);
    List *west = initializeList(printCar, deleteCar, compareCars);
    List *south = initializeList(printCar, deleteCar, compareCars);
    int count = 0;
    char trafficDir = 'N';
    char directions[4] = "NESW";
    

    if(argc > 1){
        inputFile = fopen(argv[1], "r");
    }


    while(inputFile == NULL){
        char baseDir[MAX_LEN] = "../assets/";
        printf("Invalid File Name. Please enter a valid file name.\n");
        fgets(fileName, MAX_LEN, stdin);
        removeNewLineChar(fileName);
        strcat(baseDir, fileName);

        inputFile = fopen(baseDir, "r");
    }


    char dir = '?';
    int arrTime = 0;
    char travelDir = '?';
    char info[3][10];
    int i = 0;


    while(fgets(values, MAX_LEN, inputFile)){
        removeNewLineChar(values);
        char *token = strtok(values, " ");
        i = 0;
        while(token != NULL){
            strcpy(info[i], token);
            token = strtok(NULL, " ");
            i++;
        }

        dir = info[0][0];
        travelDir = info[1][0];
        arrTime = atoi(info[2]);
        
        
        Car *c = createCar(dir, arrTime, travelDir);

        switch(dir){
            case 'N':
                insertSorted(north, c);
                break;
            case 'E':
                insertSorted(east, c);
                break;
            case 'W':
                insertSorted(west, c);
                break;
            case 'S':
                insertSorted(south, c);
                break;
            default:
                printf("Improper Direction");
                free(c);
                break;        
        }
    }

    count = 1;
    i = 0;
    trafficDir = 'Z';
    Car *currentCar = NULL;
    List *currentList = north;
    int index = 0;

    while(!isEmpty(north) || !isEmpty(east) || !isEmpty(west) || !isEmpty(south)){
        
        index = (count / 14) % 4;
        trafficDir = directions[index];
        
        switch(trafficDir){
            case 'N':
                currentList = north;
                break;
            case 'E':
                currentList = east;
                break;
            case 'W':
                currentList = west;
                break;
            case 'S':
                currentList = south;
                break;
            default:
                break;   
        }
        
        if(!isEmpty(currentList)){
            currentCar = getFromFront(currentList);
            
            if(getArrivalTime(currentCar) <= count){
                char temp = getTravelDirection(currentCar);
                switch(temp){
                    case 'F':
                        if(count % 14 < 10){
                            setFinishTime(currentCar, count + 2);
                            count++;
                            printCar(currentCar);
                            popFront(currentList);
                            
                        }
                        break;
                    case 'R':
                        if(count % 14 < 10){
                            setFinishTime(currentCar, count + 1);
                            printCar(currentCar);
                            popFront(currentList);
                        }
                        
                        break;
                    case 'L':
                        if(count % 14 < 11){
                            setFinishTime(currentCar, (count + 2.5));
                            count += 2;
                            printCar(currentCar);
                            popFront(currentList);
                        }
                        break;
                    default:
                        printf("Invalid Direction.\n");
                        break;
                }
            }
        }
        
        count++;
    }
    
    deleteList(north);
    deleteList(east);
    deleteList(west);
    deleteList(south);
    free(north);
    free(south);
    free(east);
    free(west);

    fclose(inputFile);


    return 0;
}


void removeNewLineChar(char *str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}

void popFront(List *list){
    Car *c = getFromFront(list);
    deleteNodeFromList(list, c);
}