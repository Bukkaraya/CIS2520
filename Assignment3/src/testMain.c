#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableAPI.h"
#define TABLE_SIZE 100


void printTestInfo(int n, char *info);
int printPassFail(int b);
void printInt(void *data);
void printStr(void *data);
void deleteData(void *data);
int hashFunction(size_t size, char *key);


int main(int argc, char **argv){
    printf("Test is running...\n\n\n");
    int numTests = 0;
    int testsPassed = 0;
    HTable *testTable2 = createTable(TABLE_SIZE, hashFunction, deleteData, printInt);

    char *test1 = malloc(sizeof(char)*7);
    strcpy(test1, "Value1");

    char *test2 = malloc(sizeof(char)*7);
    strcpy(test2, "Value2");

    int *n1 = malloc(sizeof(int));
    *n1 = 5;

    int *n2 = malloc(sizeof(int));
    *n2 = 64;

    //Testing the createTable function
    printTestInfo(++numTests, "Testing to make sure the HashTable has been dynamically allocated and the table inside is also dynamically allocated.");
    HTable *testTable = createTable(TABLE_SIZE, hashFunction, deleteData, printStr);
    printf("Expected: 1, 1\n");
    printf("Received: %d, %d\n", testTable != NULL, testTable->table != NULL);
    printf("1 implies the condition has been evaluated to true. Checking if HashTable and table in side it are not NULL.\n");
    testsPassed += printPassFail(testTable != NULL && testTable->table != NULL);

    //Testing createNode function
    printTestInfo(++numTests, "Testing to make sure the a node has been dynamically allocated.");
    Node *n = createNode("key1", test1);
    printf("Expected: 1\n");
    printf("Received: %d\n", n != NULL);
    printf("1 implies the condition has been evaluated to true. Checking if node is not equal to NULL.\n");
    testsPassed += printPassFail(n != NULL);
    free(n->key);
    free(n);

    //Testing insertData function
    printTestInfo(++numTests, "Testing to make sure the given data has been inserted in the hash table. Value type is 'Char */ String'.");
    insertData(testTable, "key1", test1);
    printf("Expected: \n60 : key1 : Value1\n");
    printf("Received: \n");
    printTable(testTable);
    testsPassed += printPassFail(lookUpData(testTable, "key1") != NULL);

    printTestInfo(++numTests, "Testing to make sure the given data has been inserted in the hash table. Value type is 'int *'.");
    insertData(testTable2, "key1", n1);
    printf("Expected: 60 : key1 : 5\n");
    printf("Received: \n");
    printTable(testTable2);
    testsPassed += printPassFail(lookUpData(testTable, "key1") != NULL);

    insertData(testTable, "key2", test2);
    insertData(testTable2, "key2", n2);

    //Testing lookUpData funtion
    printTestInfo(++numTests, "Testing to make sure NULL is returned when key is not present in the hash table.");
    char *str3 = lookUpData(testTable, "key3");
    printf("Expected: 1\n");
    printf("Received: %d\n", str3 == NULL);
    printf("1 implies the condition has been evaluated to true. Checking if data is equal to NULL.\n");
    testsPassed += printPassFail(str3 == NULL);

    printTestInfo(++numTests, "Testing to make sure value is returned when key is present in the hash table.");
    int *n3 = (int *) lookUpData(testTable2, "key2");
    printf("Expected: 64\n");
    printf("Received: %d\n", *n3);
    testsPassed += printPassFail(n3 != NULL);

    //Testing removeData function
    printTestInfo(++numTests, "Testing to make sure key is removed from the table if it is present in the hash table.");
    removeData(testTable, "key1");
    printf("Expected: \n72 : key2 : Value2\n");
    printf("Received: \n");
    printTable(testTable);
    testsPassed += printPassFail(lookUpData(testTable, "key1") == NULL);

    printTestInfo(++numTests, "Testing to make sure key is not removed if it is not present in the hash table.");
    removeData(testTable2, "key3");
    printf("Expected: \n60 : key1 : 5\n72 : key2 : 64\n");
    printf("Received: \n");
    printTable(testTable2);
    testsPassed += printPassFail(lookUpData(testTable2, "key3") == NULL);

    //Testing destroyTable function
    printTestInfo(++numTests, "Testing to make sure hash table is completely destroyed. Checking with valgrind will ensure all memory has been free'd.");
    destroyTable(testTable);
    testTable = NULL;
    printf("Expected: 1\n");
    printf("Received: %d\n", testTable == NULL);
    testsPassed += printPassFail(testTable == NULL);

    destroyTable(testTable2);


     printf("%d of %d tests passed.\n", testsPassed, numTests);

    return 0;
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


void printStr(void *data){
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


void printInt(void *data){
    int *n = (int *) data;
    printf("%d\n", *n);
}


void deleteInt(void *data){
    if(data != NULL){
        free(data);
    }
}



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