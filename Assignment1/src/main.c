#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "traffic.h"

int main(int argc, char ** argv){
    printf("Starting Main Program\n");
    printf("Filename: %s", argv[1]);
    FILE* fp = fopen(argv[1], 'r');
    if(fp != NULL){
        printf("File has been opened!");
    }

    fclose(fp);

    return 0;
}