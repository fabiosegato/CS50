#include <stdio.h>

int main(void){

    int numbers[] = {4,6,8,2,7,5,1};

    for(int i=0;i<7;i++){
        printf("%i\n",i);
        if(numbers[i] == 0){
            printf("Founded! in %i\n",i);
            return 0;
        }
    }
    printf("Not Founded!\n");
    return 1;
}