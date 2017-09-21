#include <stdio.h>
#include <stdlib.h>
#include "book.h"


Book* createBook(char * title, double price){
    Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}


double getPrice(Book * b){ 
    return b->price;
}


char* getName(Book *b){
	return b->name;
}


void printBook(void * b){
    b = (Book *) b;
    printf("%s : %.3f\n", getName(b), getPrice(b) );
}