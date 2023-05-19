#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){

    char *k_char;
    string msg = get_string("Plan text: ");
    int conv = strtol(argv[1], &k_char, 10);
    int k = conv%26;

   for(int i=0;i<=strlen(msg);i++){

      if (isupper(msg[i])) {

           if((int) msg[i]+k > 90){
               printf("%c",(int) msg[i]+(65+k-91));
           }
           else {
               printf("%c",(int) msg[i]+k);
           }
       } else if (islower(msg[i])) {

           if((int) msg[i]+k > 122){
               printf("%c",(int) msg[i]+(97+k-123));
           }
           else {
               printf("%c",(int) msg[i]+k);
           }
       } else {
           printf("%c",(int) msg[i]);
       }

   }

    printf("\n");

}