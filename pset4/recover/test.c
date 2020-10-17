#include<stdio.h>

int main()
{
    FILE *f = fopen("card.raw", "r");
    if (f == NULL)
    {
        printf("Error reading the file\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    // float len = ftell(f);
    float nb = ftell(f) / 512;

    // printf("Size: %f bytes\n", len);
    printf("%f blocks of 512 bytes\n", nb);

    return 0;
}