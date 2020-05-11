// Asking for person's name and greeting the person, using cs50.h too
#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string answer = get_string("What is your name? ");
    printf("Hello, %s!\n", answer);
}

