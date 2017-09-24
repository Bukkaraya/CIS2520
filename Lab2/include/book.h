#ifndef BOOK_H
#define BOOK_H

/**
 * Stores information related to the book
*/
typedef struct book {
    double price;
    char *name;
} Book;

/**
 * [createBook description]
 * @param title static string of title
 * @param price double
 * @return a dynamically created Book
 */
Book* createBook(char * title, double price);

/**
 * Get name of the book
 * @param b Book
 * @return char* string of name
 */
char* getName(Book *b);

/**
 * Get price of book
 * @param b Book
 * @return Double price
 */
double getPrice(Book * b);

/**
 * Display a book's name and price
 * @param b [Book]
 */
void printBook(void * b);

#endif