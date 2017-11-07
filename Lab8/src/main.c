#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 100



/**
 * Print an array of integers with a specific length.
 */
void printArray(int* arr, int length);

void removeNewLine(char *str);

/**
 * Create a typedef for a  Compare Function 
 */
typedef int (*CompareFunc)(void* a, void* b);


/*
 * Compare function that 
 * returns 1 if a > b
 * returns -1 if a < b
 * returns 0 if a == b
*/
int compareAscend(void *a, void *b);

/*
 * Compare function that 
 * returns -1 if a > b
 * returns 1 if a < b
 * returns 0 if a == b
*/
int compareDescend(void *a, void *b);


/*
 * Compare function that that is used to sort an array in increasing order with all even numbers before odd numbers.
*/
int compareEven(void *a, void *b);

/**
 * Create a typedef for a Sort Algorithm of an array
 */
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

/* 
 * Function that takes in an array, the size of the array and the compare function and sorts it using the bubble
 * sorting algorithm
*/
void bubbleSort(int *container, int length, CompareFunc cf);

/* 
 * Function that takes in an array, the size of the array and the compare function and sorts it 
 * using the insert sort algorithm
*/
void insertSort(int *container, int length, CompareFunc cf);

/***
 * NOTE: You will implement this function, it will be used to call all sorting algorithms. 
 *      It will also output the all the information required by the output section of the lab.
 *       
 * menuSelection is the text for the menu option that was selected.
 * sorter -> is the sorting function
 * array -> is the input array given by the user
 * length-> is the length of the array
 * compare -> is a comparison function pointer.
 */
void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare);


int main(int argc, char ** argv ){
    int len = 0;

    printf("Please enter the size of the array:\n");
    scanf("%d", &len);
    getchar();
    int someArray[len];

    printf("Please enter the %d numbers:\n", len);
    
    for(int i = 0; i < len; i++){
        scanf("%d", &someArray[i]);
        getchar();
    }

    char userInput[MAX_LEN];
    int input = 0;
    SortAlgorithm sorter;
    CompareFunc comp;

    while(1){
        printf("Please enter your choice:\n");
        fgets(userInput, MAX_LEN, stdin);
        removeNewLine(userInput);
        input = atoi(userInput);
        switch(input){
            case 1:
                comp = compareAscend;
                sorter = bubbleSort;
                break;
            case 2:
                comp = compareDescend;
                sorter = bubbleSort;
                break;
            case 3:
                comp = compareEven;
                sorter = bubbleSort;
                break;
            case 4:
                comp = compareAscend;
                sorter = insertSort;
                break;
            case 5:
                comp = compareDescend;
                sorter = insertSort;
                break;
            case 6:
                comp = compareEven;
                sorter = insertSort;
                break;
            case 7:
                printf("GoodBye!\n");
                break;
            default:
                printf("Improper input, please try again.\n");
                break;
        }

        if(input == 7){
            break;
        }

        sort(userInput, sorter, someArray, len, comp);
    }
    

    return 0;
}


void printArray(int* arr, int length){
	for(int i =0 ; i < length; i++){
        printf("%d ", arr[i]);
    } 
	printf("\n");
}


void removeNewLine(char *str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}


int compareAscend(void *a, void *b){
    int *n1 = (int *) a;
    int *n2 = (int *) b;
    if(*n1 > *n2){
        return 1;
    }else if(*n1 < *n2){
        return -1;
    }else{
        return 0;
    }
}


int compareDescend(void *a, void *b){
    int *n1 = (int *) a;
    int *n2 = (int *) b;
    if(*n1 > *n2){
        return -1;
    }else if(*n1 < *n2){
        return 1;
    }else{
        return 0;
    }
}


int compareEven(void *a, void *b){
    int *n1 = (int *) a;
    int *n2 = (int *) b;
    if(*n1 % 2 == 1){
        if(*n2 % 2 == 0){
            return 1;
        }else{
            if(*n1 > *n2){
                return 1;
            }else{
                return -1;
            }
        }
    }else if(*n1 % 2 == 0){
        if(*n2 % 2 == 0 && *n1 > *n2){
            return 1;
        }
        return -1;
    }else{
        return 0;
    }
}


void bubbleSort(int *container, int length, CompareFunc cf){
    int temp = 0;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(cf(&container[j], &container[j + 1]) >= 0){
                temp = container[j];
                container[j] = container[j + 1];
                container[j + 1] = temp;
            }
        }
    }
}


void insertSort(int *container, int length, CompareFunc cf){
    int i = 0;
    int j = 0;
    int temp = 0;
    while(i < length){
        j = i;
        while(j > 0 && cf(&container[j - 1], &container[j]) >= 0){
            temp = container[j - 1];
            container[j - 1] = container[j];
            container[j] = temp;
            j--;
        }
        i++;
    }
}



void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare){
    int select = atoi(menuSelection);
    switch(select){
        case 1:
            printf("Bubble Sort (Increasing Order):\n");
            break;
        case 2:
            printf("Bubble Sort (Decreasing Order):\n");
            break;
        case 3:
            printf("Bubble Sort (Increasing order with even numbers first):\n");
            break;
        case 4:
            printf("Insert Sort (Increasing Order):\n");
            break;
        case 5:
            printf("Insert Sort (Decreasing Order):\n");
            break;
        case 6:
            printf("Insert Sort (Increasing order with even numbers first):\n");
            break;
        default:
            break;
    }
    
    sorter(array, length, compare);
    printf("Result Array: ");
    printArray(array, length);
}