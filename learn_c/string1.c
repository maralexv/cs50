// Ask for name and greet the person using only stdio.h
#include<stdio.h>

int main(void)
{
    char answer[64];
    int dig;
    printf("What is your name? ");
    scanf("%s", answer);
    printf("Hello, %s!\n", answer);

    printf("Characteer: ");
    scanf("%d", &dig);
    printf("%c\n", answer[dig]);
}