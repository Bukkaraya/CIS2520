#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTreeAPI.h"
#include "rule.h"
#define MAX_LEN 400




int main(int argc, char** argv){
    FILE* inputFile = NULL;
    char fileName[MAX_LEN];
    char fileValues[MAX_LEN];
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

    while(fgets)


    return 0;
}