// Validates whether a credit/debit card is a valid AMEX, MC or VISA card
#include<stdio.h>
#include<math.h>
#include<cs50.h>

// Initialise funcs, used later in the code
int get_card_number(void);
int card_num_length(long cnum);
int card_type(long card_number, int num_length);


// Main block where the program starts
int main(void)
{
    long card_number = get_card_number();
    int num_length = card_num_length(card_number);
    int first_digts = card_type(card_number, num_length);
}

// User inputs the credit/debit card number
int get_card_number(void)
{
    long card_number;
    do
    {
        card_number = get_long("Your card number: ");
    }
    while (card_number <=0);
    printf("card number: %li\n", card_number);
    return card_number;
}

// Length of card number
int card_num_length(long cnum)
{
    int num_length = 0;
    while (cnum !=0)
    {
        cnum /= 10;
        num_length++;
    }
    printf("number length: %d\n", num_length);
    return num_length;
}

// Determin type of the card
int card_type(long card_number, int num_length)
{
    int initial_digits = card_number / pow(10, (num_length - 2));
    printf("first 2 digits: %d\n", initial_digits);

    return initial_digits;
}

// Validity check
