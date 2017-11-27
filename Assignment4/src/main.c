#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarySearchTreeAPI.h"
#include "rule.h"
#define MAX_LEN 400

void removeNewLine(char* str);


int main(int argc, char** argv){
    FILE* inputFile = NULL;
    char fileName[MAX_LEN];
    char fileValues[MAX_LEN];
    char secondValue[MAX_LEN];
    Tree *wordTree = createBinTree(compareRules, deleteRule);


    if(argc > 1){
        inputFile = fopen(argv[1], "r");
    }

    //If file file cannot be opened prompt the user
    while(inputFile == NULL){
        printf("Invalid file name, please try again.\n");
        fgets(fileName, MAX_LEN, stdin);
        removeNewLine(fileName);
        inputFile = fopen(fileName, "r");
    }

    printf("Successfully opened the file.\n");

    while(fgets(fileValues, MAX_LEN, inputFile)){
        fgets(secondValue, MAX_LEN, inputFile);
        printf("%s%s\n", fileValues, secondValue);
    }


    return 0;
}



void removeNewLine(char* str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}