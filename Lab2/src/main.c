#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "boardgame.h"
#include "store.h"

int main(int argc, char** argv){
    Book *b1 = createBook("Eye of the World", 8.99);
    Book *b2 = createBook("One Piece", 4.99);
    BoardGame *bg1 = createBoardGame("Monopoly", 32.50, "Hasbro");
    BoardGame *bg2 = createBoardGame("Dungeons and Dragons", 40.00, "Wizards");
    Store *store = createStore(b1, printBook);

    displayStore(store);
    changeStoreItem(store, b2, printBook);
    displayStore(store);
    changeStoreItem(store, bg1, printBoardGame);
    displayStore(store);
    changeStoreItem(store, bg2, printBoardGame);
    displayStore(store);

    free(b1);
    free(b2);
    free(bg1);
    free(bg2);
    free(store);

    store = NULL;
    bg1 = NULL;
    bg2 = NULL;
    b1 = NULL;
    b2 = NULL;

    return 0;
}