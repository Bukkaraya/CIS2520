#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableAPI.h"

HTable *createTable(size_t size, int (*hashFunction) (size_t tableSize, char *key), void (*destroyData) (void *data), void (*printNode) (void *data)){
    HTable *hashTable = malloc(sizeof(HTable));
    hashTable->size = size;
    hashTable->table = malloc(sizeof(Node*) * size);

    //Initialize all values of hash table to NULL
    int i = 0;
    for(i = 0; i < size; i++){
        hashTable->table[i] = NULL;
    }

    hashTable->destroyData = destroyData;
    hashTable->hashFunction  = hashFunction;
    hashTable->printNode = printNode;

    return hashTable;
}


Node *createNode(char *key, void*data){
    Node *node = malloc(sizeof(Node));

    node->key = malloc(sizeof(char) * strlen(key) + 1);
    strncpy(node->key, key, strlen(key) + 1);

    node->next = NULL;
    node->data = data;

    return node;
}


void destroyTable(HTable *hashTable){
    if(hashTable){
        int i = 0;
        for(i = 0; i < hashTable->size; i++){
            Node *n = hashTable->table[i];
            Node *temp = NULL;
            while(n != NULL){
                temp = n;
                hashTable->destroyData(temp->data);
                free(n->key);
                n->key = NULL;
                n = n->next;
                free(temp);
            }
        }
        free(hashTable->table);
        hashTable->table = NULL;
        free(hashTable);
        hashTable = NULL;
    }
}


void insertData(HTable *hashTable, char *key, void *data){
    if(hashTable){
        Node *newNode = createNode(key, data);
        int hashNum = hashTable->hashFunction(hashTable->size, key);
        Node *pos = hashTable->table[hashNum];
        if(pos == NULL){
            hashTable->table[hashNum] = newNode;
        }else{
            if(pos != NULL){
                Node *cur = pos;
                while(cur->next != NULL){
                    cur = cur->next;
                }
                cur->next = newNode;
            }
        }
    }
}


void *lookUpData(HTable *hashTable, char *key){
    if(hashTable){
        int hashNum = hashTable->hashFunction(hashTable->size, key);
        Node *head = hashTable->table[hashNum];
        if(head != NULL){
            Node *cur = head;
            while(cur != NULL){
                if(strcmp(cur->key, key) == 0){
                    break;
                }
                cur = cur->next;
            }
            if(cur != NULL){
                return cur->data;
            }
        }
    }

    return NULL;
}


void removeData(HTable *hashTable, char *key){
    if(hashTable){
        int hashNum = hashTable->hashFunction(hashTable->size, key);
        Node *head = hashTable->table[hashNum];
        if(head != NULL){
            if(head->next == NULL){
                hashTable->destroyData(head->data);
                free(head->key);
                free(head);
                head = NULL;
                hashTable->table[hashNum] = NULL;
            }
            Node *cur = head;
            while(cur != NULL){
                if(strcmp(cur->key, key) == 0){
                    break;
                }
                cur = cur->next;
            }
            if(cur != NULL){
                Node *temp = cur;
                cur = cur->next;
                hashTable->destroyData(temp->data);
                free(temp->key);
                free(temp);
            }
        }
    }
}


void printTable(HTable *hashTable){
    int i = 0;
    for(i = 0; i < hashTable->size; i++){
        Node *head = hashTable->table[i];
        Node *cur = head;
        while(cur != NULL){
            printf("%d : %s : ", hashTable->hashFunction(hashTable->size, cur->key), cur->key);
            hashTable->printNode(cur->data);
            cur = cur->next;
        }
    }
}