#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"
#define MAX_NUMLEN 11

void printInt(void *data);
void deleteInt(void *data);
int compareInts(const void *first, const void *second);
void removeNewLine(char *str);


int main(int argv, char** argc){
    char input[MAX_NUMLEN];
    Stack *squash = createStack(printInt, deleteInt, compareInts);
    void *head = NULL;
    int *topNum = NULL;


    while(1){
        printf("Enter a number(Negative number to exit program):\n");
        fgets(input, MAX_NUMLEN, stdin);
        removeNewLine(input);
        topNum = malloc(sizeof(int));
        *topNum = atoi(input);

        if(*topNum < 0){
            free(topNum);
            printf("Bye!\n");
            break;
        }
        
        head = top(squash);
        
        if(head != NULL){
            while(head != NULL && compareInts(topNum, head) >= 0){
                printInt(topNum);
                printf(" squashed ");
                printInt(head);
                printf("\n");
                pop(squash);
                head = top(squash);
            }
            push(squash, topNum);
        }else{
            push(squash, topNum);
        }

        printf("Remaining: ");
        printInt(top(squash));
        printf("\n");
    }

    destroyStack(squash);

    return 0;
}


void printInt(void *data){
    int *n = (int *) data;
    printf("%d", *n); 
}


int compareInts(const void *first, const void *second){
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


void deleteInt(void *data){
    if(data != NULL){
        free(data);
        data = NULL;
    }
}


void removeNewLine(char *str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}