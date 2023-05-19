#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("fabio gostoso \n");
  int num1 = get_int("primeiro numero: \n");
  int num2 = get_int("segundo numero: \n");
  int total = num1+num2;

  printf("soma: %i\n",total);

  if(total >= 100) {
      printf("soma maior ou igual a 100 \n");
  } else {
       printf("soma menor que 100 \n");

  }

}