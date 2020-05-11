#include <stdio.h>

int main()
{
    int num;
    printf("Give me an integer: ");
    scanf("%d", &num);
    switch(num)
    {
        case 0:
            printf("you gave me %d!\n", num);
            break;
        case 1:
            printf("you gave me %d!\n", num);
            break;
        case 2:
            printf("you gave me %d!\n", num);
            break;
        default:
            printf("you gave me way too high digit! blast off\n");
    }
    
    return 0;
}