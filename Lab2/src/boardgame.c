#include <stdio.h>
#include <stdlib.h>
#include "boardgame.h"


/*
 * [createStore description]
 * @param name static string of the name of the boardgame
 * @param price double
 * @param brandName static string of brand name
 * @return dynamically created BoardGame
*/
BoardGame* createBoardGame(char* name, double price, char* brandName){
    BoardGame* bg = malloc(sizeof(BoardGame));
    bg->name = name;
    bg->price = price;
    bg->brandName = brandName;
    return bg;
}

/*
 * Get name of board game
 * @param bg BoardGame
 * @return char* string of name
*/
char* getBGName(BoardGame *bg){
    return bg->name;
}

/*
 * Get price of board game
 * @param bg BoardGame
 * @return Double price
*/
double getBGPrice(BoardGame *bg){
    return bg->price;
}

/*
 * Get brand name of board game
 * @param bg BoardGame
 * @return char* string of brand name
*/
char* getBrandName(BoardGame *bg){
    return bg->brandName;
}

/*
 * Display the board game's name, price and brand name
 * @param bg [BoardGame]
*/  
void printBoardGame(void *bg){
    bg = (BoardGame *) bg;
    printf("%s: %.3lf - %s\n", getBGName(bg), getBGPrice(bg), getBrandName(bg));
}