#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{

//declare variables
    char *card_number = get_string("whats your card number? ");
    int card_number_length = strlen(card_number);
    int sum_even =0;
    int sum_odd =0;
    int flag_card =0;

//validate card number
    for(int i=card_number_length-1;i>=0;i--) {
         int number = (int) card_number[i] -48;

        if((i%2)==0) {
            sum_even += (number*2/10)+(number*2%10);
        }
        else {
            sum_odd += number;
        }
    }

//check if card num is valid  4003600000000014
    if((sum_even+sum_odd)%10 == 0) {
        //get flag card
        flag_card = ((int) card_number[0] -48);
        if(flag_card==3){
            printf("AMEX\n");
        } else if (flag_card==5){
            printf("MASTER\n");
        } else if (flag_card==4){
            printf("VISA\n");
        }
        printf("Thas a valid card number!\n");
    } else {
        printf("Thas a invalid card number!\n");
    }
}