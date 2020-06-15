// Ask for name and greet the person using only stdio.h
#include<stdio.h>

int main(void)
{
    char *answer;
    int dig;
    // printf("What is your name? ");
    // scanf("%s", &answer);
    // printf("Hello, %s!\n", *answer);

    printf("Character: ");
    scanf("%i", &dig);
    printf("%c\n", dig);
}