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
void addWordToDict(HTable *hashTable);
void removeWordFromDict(HTable *hashTable);
void checkFile(HTable *hashTable);


int main(int argc, char **argv){
    FILE* inputFile = NULL;
    char fileName[MAX_LEN];
    char fileValues[MAX_LEN];
    char *word = NULL;
    HTable *wordsTable = createTable(TABLE_SIZE, hashFunction, deleteData, printFunction);
    int userInput = 0;


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

    //Start Main Loop
    while(userInput != 5){
        //Add error checking for this part
        printf("Please enter your choice:\n");
        scanf("%d", &userInput);
        getchar();
        switch(userInput){
            case 1:
                addWordToDict(wordsTable);
                break;
            case 2:
                removeWordFromDict(wordsTable);
                break;
            case 3:
                checkFile(wordsTable);
                break;
            case 4:
                printTable(wordsTable);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Input.");
                break;
        }
    }

    destroyTable(wordsTable);

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


void addWordToDict(HTable *hashTable){
    char temp[MAX_LEN];
    char *value = NULL;

    printf("Please enter the word you want to add:\n");
    fgets(temp, MAX_LEN, stdin);
    removeNewLine(temp);

    value = malloc(sizeof(char) * strlen(temp) + 1);
    strncpy(value, temp, strlen(temp) + 1);
    insertData(hashTable, value, value);

    printf("The word %s has been added to the dictionary.\n", temp);
}


void removeWordFromDict(HTable *hashTable){
    char temp[MAX_LEN];

    printf("Please enter the word you want to remove:\n");
    fgets(temp, MAX_LEN, stdin);
    removeNewLine(temp);

    void *data = lookUpData(hashTable, temp);
    if(data == NULL){
        printf("The given word does not exists in the dictionary.\n");
    }else{
        removeData(hashTable, temp);
        printf("%s has been removed from the dictionary.\n", temp);
    }
}


void checkFile(HTable *hashTable){
    char fileName[MAX_LEN];
    char fileValues[MAX_LEN];
    int wordsNotFound = 0;
    int wordsFound = 0;
    FILE* checkFile = NULL;

    while(checkFile == NULL){
        printf("Please enter a file name to be processed by Spell Check:\n");
        fgets(fileName, MAX_LEN, stdin);
        removeNewLine(fileName);
        checkFile = fopen(fileName, "r");
        if(checkFile == NULL){
            printf("Invalid file name, please try again.\n");
        }
    }

    printf("File processed by Spell Check %s\n", fileName);

    while(fgets(fileValues, MAX_LEN, checkFile)){
        removeNewLine(fileValues);
        char* wordFound = lookUpData(hashTable, fileValues);
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

    fclose(checkFile);
    checkFile = NULL;
}