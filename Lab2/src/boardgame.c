#include <stdio.h>
#include <stdlib.h>
#include "boardgame.h"


BoardGame* createBoardGame(char* name, double price, char* brandName){
    BoardGame* bg = malloc(sizeof(BoardGame));
    bg->name = name;
    bg->price = price;
    bg->brandName = brandName;
    return bg;
}

char* getBGName(BoardGame *bg){
    return bg->name;
}

double getBGPrice(BoardGame *bg){
    return bg->price;
}

char* getBrandName(BoardGame *bg){
    return bg->brandName;
}

void printBoardGame(void *boardgame){
    BoardGame *bg = (BoardGame *) boardgame;
    printf("%s: %.3lf - %s\n", getBGName(bg), getBGPrice(bg), getBrandName(bg));
}