#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int number_1 = get_int("type the first number:");
    printf("First number is: %i\n",number_1);
    int number_2 = get_int("type the second number:");
    printf("Second number is: %i\n",number_2);
    int sum = number_1 + number_2;
    printf("Adding the too numbers: %i\n",sum);
}