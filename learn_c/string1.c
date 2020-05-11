// Ask for name and greet the person using only stdio.h
#include<stdio.h>

int main(void)
{
    char answer[64];
    printf("What is your name? ");
    scanf("%s", answer);
    printf("Hello, %s!\n", answer);
}