#include<stdio.h>
#include<cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char *s = get_string("s: \n");
    char *t = malloc(strlen(s)+1);

     strcpy(t,s);

   t[0] = toupper(t[0]);;

    printf("s: %s t: %s",s,t);

}