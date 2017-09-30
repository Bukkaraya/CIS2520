#include <stdio.h>
#include <stdlib.h>
#include "book.h"

Book* createBook(char * title, double price){
    Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}

char* getName(Book *b){
	return b->name;
}

double getPrice(Book * b){ 
    return b->price;
}

void printBook(void * book){
    Book *b = (Book *) book;
    printf("%s : %.3f\n", getName(b), getPrice(b) );
}

int compareBook(const void *first, const void *second){
    Book *b1 = (Book *) first;
    Book *b2 = (Book *) second;

    if(b1->price > b2->price){
        return 1;
    }else if(b1->price < b2->price){
        return -1;
    }else{
        return 0;
    }
}