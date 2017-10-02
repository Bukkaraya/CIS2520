#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("Starting Tests.");
    int num = 0;
    int i = 0;
    for(i = 0; i < 100; i++){
        num = i / 14 % 4;
        printf("%d\n", num);
        if(i % 14 == 0){
            printf("--------------\n");
        }
    }

    return 0;
}