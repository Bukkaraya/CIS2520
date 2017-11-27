#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTreeAPI.h"


int compareInt(const void *first, const void *second){
    int *n1 = (int *) first;
    int *n2 = (int *) second;

    if(*n1 > *n2){
        return 1;
    }else if(*n1 < *n2){
        return -1;
    }else{
        return 0;
    }

}

void printInt(void *data){
    int *n = (int *) data;
    printf("%d\n", *n);
}


void deleteFunc(void* data){
    if(data != NULL){
        free(data);
    }
}


int main(int argc, char** argv){
    
    printf("Test is running.");
    
    return 0;
}