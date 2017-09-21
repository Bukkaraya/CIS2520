#include <stdio.h>
#include <stdlib.h>
#include "boardgame.h"

BoardGame* createBoardGame(char* name, float price, char* brandName){
    BoardGame* bg = malloc(sizeof(BoardGame));
    bg->name = name;
    bg->price = price;
    bg->brandName = brandName;
    return bg;
}

char* getBGName(BoardGame *bg){
    return bg->name;
}


float getBGPrice(BoardGame *bg){
    return bg->price;
}


char* getBrandName(BoardGame *bg){
    return bg->brandName;
}


void printBoardGame(void *bg){
    bg = (BoardGame *) bg;
    printf("%s: %.3f - %s\n", getBGName(bg), getBGPrice(bg), getBrandName(bg));
}