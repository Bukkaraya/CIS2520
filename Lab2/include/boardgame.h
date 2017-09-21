typedef struct BoardGame{
    char *name;
    float price;
    char *brandName;
} BoardGame;

BoardGame* createBoardGame(char* name, float price, char* brandName);
char* getBGName(BoardGame *bg);
float getBGPrice(BoardGame *bg);
char* getBrandName(BoardGame *bg);
void printBoardGame(void *bg);