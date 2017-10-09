#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *fp = fopen(argv[1], "r");
    char posn = '?';
    int arrTime = 0;
    char dir = '?';


    while(fscanf(fp, "%c %c %d\n", &posn, &dir, &arrTime) == 3){
        printf("%c %c %d\n", posn, dir, arrTime);   
    }


    fclose(fp);

    return 0;
}