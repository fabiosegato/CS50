#include <stdio.h>
#include <cs50.h>

int main(void)
{
int n = get_int("Whats the height? \n");

    for (int i=0;i<n;i++){

        for (int j =0;j<n-i;j++){
            printf(" ");
        }

        for (int j =0;j<=i;j++){
            printf("#");
        }

        printf(" ");

        for (int j =0;j<=i;j++){
            printf("#");
        }
         printf("\n");
    }

}


