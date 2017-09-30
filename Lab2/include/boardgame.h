#ifndef BOARD_GAME_H
#define BOARD_GAME_H

/**
 * Stores information related to the boardgame
*/
typedef struct BoardGame{
    char *name;
    float price;
    char *brandName;
} BoardGame;

/**
 * [createStore description]
 * @param name static string of the name of the boardgame
 * @param price double
 * @param brandName static string of brand name
 * @return dynamically created BoardGame
*/
BoardGame* createBoardGame(char* name, double price, char* brandName);

/**
 * Get name of board game
 * @param bg BoardGame
 * @return char* string of name
*/
char* getBGName(BoardGame *bg);

/**
 * Get price of board game
 * @param bg BoardGame
 * @return Double price
*/
double getBGPrice(BoardGame *bg);

/**
 * Get brand name of board game
 * @param bg BoardGame
 * @return char* string of brand name
*/
char* getBrandName(BoardGame *bg);

/**
 * Display the board game's name, price and brand name
 * @param boardgame [BoardGame]
*/  
void printBoardGame(void *boardgame);

#endif