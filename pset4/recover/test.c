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
    float nb = ftell(f) / 512;
    printf("%f blocks of 512 bytes\n", nb);

    fseek(f, 0, SEEK_SET);

    int c;
    int i = 0;
    while (1)
    {
        if (feof(f))
        {
            break;
        }
        c = fgetc(f);

        if (c == 0xff)
        {
            printf("i = %d, c = %x, position = %ld.\n", i, c, ftell(f));
        }
        ++i;
    }

    return 0;
}