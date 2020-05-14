// Validates whether a credit/debit card is a valid AMEX, MC or VISA card
#include<stdio.h>
#include<math.h>
#include<cs50.h>

// Initialise funcs, used later in the code
long get_card_number(void);
int card_num_length(long cnum);
int card_type(long card_number, int num_length);
string validation(long card_n, int digits);

// Main block where the program starts
int main(void)
{
    long card_numb = get_card_number();
    int num_length = card_num_length(card_numb);
    int digits = card_type(card_numb, num_length);

    // Validation using Luhn's algorithm
    int acc1 = 0;
    long cnr = card_numb;
    int r;
    
    while (cnr > 0)
    {
        cnr /= 10;
        r = cnr % 10;
        if ((r * 2)>9)
        {
            acc1 += ((r*2)%10) + ((r*2)/10);
        }
        else
        {
            acc1 += r*2;
        }
        cnr /= 10;
    }

    cnr = card_numb;
    int acc2 = acc1;
    while (cnr > 0)
    {
        r = cnr % 10;
        acc2 += r;
        cnr /= 100;
    }

    string val;
    int v = digits/10;
    if ((acc2 % 10) != 0 || num_length < 13)
    {
        val = "INVALID\n";
    }
    else if (digits == 34 || digits == 37)
    {
        val = "AMEX\n";
    }
    else if (digits == 51 || digits == 52 || digits == 53 || digits == 54 || digits == 55 || digits == 22)
    {
        val = "MASTERCARD\n";
    }
    else if (v == 4)
    {
        val = "VISA\n";
    }
    else
    {
        val = "INVALID\n";
    }
    
    printf("%s", val);
    return 0;
}

// User inputs the credit/debit card number
long get_card_number(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number <=0);

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

    return num_length;
}

// Determin type of the card
int card_type(long card_num, int num_len)
{
    int two_digits = card_num / pow(10, (num_len - 2));

    return two_digits;
}
