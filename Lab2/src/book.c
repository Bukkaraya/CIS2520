#include <stdio.h>
#include <stdlib.h>
#include "book.h"

/**
 * [createBook description]
 * @param title static string of title
 * @param price double
 * @return a dynamically created Book
 */
Book* createBook(char * title, double price){
    Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}

/**
 * Get price of book
 * @param b Book
 * @return Double price
 */
char* getName(Book *b){
	return b->name;
}

/**
 * Get name of the book
 * @param b Book
 * @return char* string of name
 */
double getPrice(Book * b){ 
    return b->price;
}

/**
 * Display a book's name and price
 * @param b [Book]
 */
void printBook(void * b){
    b = (Book *) b;
    printf("%s : %.3f\n", getName(b), getPrice(b) );
}