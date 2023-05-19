#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int counter =0;
  long inicial_population=0;
  long limit_population=0;
  
  while(inicial_population<9){
    inicial_population = get_long("Whats the actual lhamas population? value higher then 8 \n");
  }

  while(limit_population<inicial_population){
    limit_population = get_long("Whats the limit of lhamas population? value higher then %li \n",inicial_population);
  }

  while (inicial_population<limit_population) {
      counter++;
      inicial_population = (inicial_population + (inicial_population/3))- (inicial_population/4);
  }

  printf("Total population %li\n",inicial_population);
  printf("%i anos\n ",counter);

}