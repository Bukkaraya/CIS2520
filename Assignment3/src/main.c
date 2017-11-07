#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableAPI.h"
#define MAX_LEN 100
#define TABLE_SIZE 200

void removeNewLine(char* str);
int strEmpty(char* str);
void printHyphens(int num);
int getPositiveInt();
int hashFunction(size_t size, char *key);
void printFunction(void *data);
void deleteData(void *data);


int main(int argc, char **argv){
    FILE* inputFile = NULL;
    char fileName[MAX_LEN];
    char fileValues[MAX_LEN];
    char *word = NULL;
    HTable *wordsTable = createTable(TABLE_SIZE, hashFunction, deleteData, printFunction);

    if(argc > 1){
        inputFile = fopen(argv[1], "r");
    }

    //Prompt User
    while(inputFile == NULL){
        printf("Invalid file name, please try again.\n");
        fgets(fileName, MAX_LEN, stdin);
        removeNewLine(fileName);
        inputFile = fopen(fileName, "r");
    }

    printf("Successfully opened the file.\n");

    //Get data from file and store in data structures
    while(fgets(fileValues, MAX_LEN, inputFile)){
        removeNewLine(fileValues);
        word = malloc((sizeof(char) * strlen(fileValues)) + 1);
        strncpy(word, fileValues, strlen(fileValues) + 1);
        insertData(wordsTable, word, word);
    }

    //Closing the file
    fclose(inputFile);
    inputFile = NULL;

    printTable(wordsTable);

    while(inputFile == NULL){
        printf("Enter file you want to check with.\n");
        fgets(fileName, MAX_LEN, stdin);
        removeNewLine(fileName);
        inputFile = fopen(fileName, "r");
    }

    int wordsNotFound = 0;
    int wordsFound = 0;

    while(fgets(fileValues, MAX_LEN, inputFile)){
        removeNewLine(fileValues);
        char* wordFound = lookUpData(wordsTable, fileValues);
        if(wordFound == NULL){
            printf("%s was not found in the dictionary.\n", fileValues);
            wordsNotFound++;
        }else{
            wordsFound++;
        }
    }

    printf("Summary\n");
    printf("Correctly Spelt Words: %d\n", wordsFound);
    printf("Incorrectly Spelt Words: %d\n", wordsNotFound);

    destroyTable(wordsTable);
    fclose(inputFile);
    inputFile = NULL;

    return 0;
}



void removeNewLine(char *str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}


int strEmpty(char *str){
    if(str[0] == '\0'){
        return 1;
    }

    return 0;
}


int getPositiveInt(){
    int userInt = 0;
    char userStr[MAX_LEN];

    while(userInt <= 0){
        fgets(userStr, MAX_LEN, stdin);
        removeNewLine(userStr);
        userInt = atoi(userStr);
        if(userInt <= 0){
            printf("Invalid. Please try again.");
        }
    }

    return userInt;
}


void printHyphens(int num){
    int i = 0;
    for(i = 0; i < num; i++){
        printf("-");
    }
    printf("\n");
}


int hashFunction(size_t size, char *key){
    int i = 0;
    int hash = 0;
    for(i = 0; i < strlen(key); i++){
        hash += key[i] * i;
    }
    
    hash *= strlen(key);
    
    return hash % size;
}


void printFunction(void *data){
    if(data != NULL){
        char* str = (char *) data;
        printf("%s\n", str);
    }
}


void deleteData(void *data){
    if(data != NULL){
        free(data);
        data = NULL;
    }
}