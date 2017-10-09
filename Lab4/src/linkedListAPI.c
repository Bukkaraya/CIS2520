#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"


List *initializeList(void (*printFunction) (void * toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)){
    List *l = malloc(sizeof(List));
    
    if (l != NULL) {
        l->head = NULL;
        l->tail = NULL;
        l->deleteNode = deleteFunction;
        l->compare = compareFunction;
        l->printNode = printFunction;
    }

    return l;
}


Node *initiializeNode(void *data){
    Node *n = malloc(sizeof(Node));
    
    if (n != NULL) {
        n->data = data;
        n->previous = NULL;
        n->next = NULL;
    }
    
    return n;
}


void insertFront(List *list, void *toBeAdded){
    Node *n = initiializeNode(toBeAdded);
    if (list->head == NULL && list->tail == NULL) {
        list->head = n;
        list->tail = n;
    } else {
        Node *temp = list->head;
        temp->previous = n;
        n->next = temp;
        list->head = n;
    }
}


void insertBack(List *list, void *toBeAdded){
    Node *n = initiializeNode(toBeAdded);
    if (list->head == NULL && list->tail == NULL) {
        list->head = n;
        list->tail = n;
    } else {
        Node *temp = list->tail;
        temp->next = n;
        n->previous = temp;
        list->tail = n;
    }
}


void deleteList(List *list){
    Node *cur = list->head;
    while (cur != NULL) {
        list->head = cur->next;
        list->deleteNode(cur->data);
        free(cur);
        cur = list->head;
    }
    free(list);
}


void insertSorted(List *list, void *toBeAdded){
    Node *n = initiializeNode(toBeAdded);
    if (list->head == NULL && list->tail == NULL) {
        list->head = n;
        list->tail = n;
    } else {
        Node *cur = list->head;
        Node *pos = NULL;
        while (cur != NULL && list->compare(toBeAdded, cur->data) == 1){
            pos = cur;
            cur = cur->next;
        }

        if(pos == NULL){
            pos = list->head;
            n->next = pos;
            pos->previous = n;
            list->head = n;
        } else if (cur == NULL){
            pos = list->tail;
            n->previous = pos;
            pos->next = n;
            list->tail = n;
        }else{
            pos->next = n;
            n->next = cur;
            n->previous = pos;
            cur->previous = n;
        }
    }
}


void *getFromFront(List *list){
    if(list != NULL){
        if(list->head != NULL){
            return list->head->data;
        }
    }

    return NULL;
}


void *getFromBack(List *list){
    if(list != NULL){
        if(list->tail != NULL){
            return list->head->data;
        }
    }

    return NULL;
}


void printForward(List *list){
    if(list != NULL){
        if(list->head == NULL){
            printf("List is empty.");
        }else{
            Node *cur = list->head;
            while(cur != NULL){
                list->printNode(cur->data);
                cur = cur->next;
            }
        }
    }
}


void printBackwards(List *list){
    if(list != NULL){
        if(list->tail == NULL){
            printf("List is empty.");
        }else{
            Node *cur = list->tail;
            while(cur != NULL){
                list->printNode(cur->data);
                cur = cur->previous;
            }
        }
    }
}


int deleteNodeFromList(List *list, void *toBeDeleted){
    if(list->head == NULL || toBeDeleted == NULL){
        return EXIT_FAILURE;
    }

    Node *cur = list->head;
    
    while(cur != NULL){
        if(list->compare(cur->data, toBeDeleted) == 0){
            list->deleteNode(cur->data);
            
            if(cur->previous == NULL && cur->next == NULL){
                list->head = NULL;
                list->tail = NULL;
            }else if(cur->previous == NULL){
                cur->next->previous = NULL;
                list->head = cur->next;
            }else if(cur->next == NULL){
                cur->previous->next = NULL;
                list->tail = cur->previous;
            }else{
                cur->next->previous = cur->previous;
                cur->previous->next = cur->next;
            }
            
            free(cur);
            return EXIT_SUCCESS;
        }
        cur = cur->next;
    }

    return -1;

    
}

int isEmpty(List *list){
    if(list->head == NULL){
        return 1;
    }
    return 0;
}