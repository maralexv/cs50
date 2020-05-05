#include<stdio.h>

int main(void)
{
    char answer[10];
    printf("What is your name? ");
    scanf("%s", answer);
    printf("Hello, %s!\n", answer);
}

