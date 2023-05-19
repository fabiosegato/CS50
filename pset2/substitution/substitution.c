#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){

    //printf("%s\n",argv[1]);
    //printf("%s\n",argv[2]);

   string k = argv[1];
   char table_ukeys[26];
   char table_lkeys[26];
   string msg = get_string("Plan text: ");

   for(int i=0;i<=strlen(k);i++){

       table_ukeys[i]=toupper(k[i]);
       table_lkeys[i]=tolower(k[i]);

   }

    for(int i=0;i<=strlen(msg);i++){

        if(isupper(msg[i])){

            //printf("%i\n",(int) msg[i]-65);
            printf("%c",table_ukeys[msg[i]-65]);

        }

         if(islower(msg[i])){

            //printf("%i\n",(int) msg[i]-97);
             printf("%c",table_lkeys[msg[i]-97]);

        }

    }

    printf("\n");

}