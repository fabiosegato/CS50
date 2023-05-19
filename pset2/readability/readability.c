#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//prototypes
int strCount(string str, char c);
int strLetterCount(string str);
int strPontuationCount(string str);

int main(void){

    string text = get_string("Text ");
    int total_words = strCount(text,' ')+1;
    int total_letters = strLetterCount(text);
    int total_sentences = strPontuationCount(text);

    int grade = round((0.0588 *total_letters*100/total_words) - (0.296*total_sentences*100/total_words) - 15.8);

    if(grade <= 16) {
      if(grade >= 1) {
       printf("Grade: %i \n",grade);
      } else {
       printf("Before Grade 1 \n");
      }
    } else {
     printf("Grade 16+ \n");
    }
}

int strCount(string str, char c) {

 int number_ocurrencies = 0;

 for (int i=0,n=strlen(str);i<n;i++){

       if(str[i]==c) {
           number_ocurrencies++;
       }
    }

 return number_ocurrencies;
}

int strLetterCount(string str) {

 int number_ocurrencies = 0;

 for (int i=0,n=strlen(str);i<n;i++){

       if((str[i] > 64 &&  str[i]<91) || (str[i] > 96 &&  str[i]<123)) {
           number_ocurrencies++;
       }
    }

 return number_ocurrencies;
}

int strPontuationCount(string str) {

 int number_ocurrencies = 0;

 for (int i=0,n=strlen(str);i<n;i++){

       if(str[i]=='.' || str[i]=='?' || str[i]=='!') {
           number_ocurrencies++;
       }
    }

 return number_ocurrencies;
}