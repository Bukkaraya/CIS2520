#include <stdio.h>
#include <stdlib.h>



/**
 * Print an array of integers with a specific length.
 */
void printArray( int* arr, int length )
{
	for(int i =0 ; i < length; i++ ) 
		printf("%d ", arr[i]);
	printf("\n");
}



/**
 * Create a typedef for a  Compare Function 
 */
typedef int (*CompareFunc)(void* a, void* b);

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


/**
 * Create a typedef for a Sort Algorithm of an array
 */
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

void bubbleSort(int *container, int length, CompareFunc cf){
    int temp = 0;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(cf(&container[j], &container[j + 1]) >= 0){
                temp = container[j];
                container[j] = container[j + 1];
                container[j + 1] = temp;
                printArray(container, length);
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
    scanf("%d", &len);
    getchar();
    int someArray[len];
    for(int i = 0; i < len; i++){
        scanf("%d", &someArray[i]);
        getchar();
    }

    printArray(someArray, len);

    bubbleSort(someArray, len, compareEven);

    printArray(someArray, len);

    return 0;
}