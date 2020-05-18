#include <stdio.h>
#include <ctype.h>
int main()
{
    int i;
    // printf("All punctuation marks in C programming are: \n");
    for (i = 0; i <= 127; ++i)
        if (isalpha(i) != 0)
            printf("%c ", i);
    printf("\n");        
    return 0;
}