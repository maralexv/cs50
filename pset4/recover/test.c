#include<stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("card.raw", "r");
    if (f == NULL)
    {
        printf("Error reading the file\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    printf("size is %ld bytes, 4-byte blocks: %ld.\n", ftell(f), ftell(f) / sizeof(int));

    fseek(f, 0, SEEK_SET);

    int i = 0;
    while (1)
    {
        if (feof(f))
        {
            break;
        }
        int *b = malloc(512);
        if (b == NULL)
        {
            printf("Error!");
            return 2;
        }

        fread(b, 1, 512, f);

        if (b[0] == 0xff)
        {
            printf("i = %d, b[0] = %x, position = %ld.\n", i, b[0], ftell(f));
        }
        ++i;
        free(b);
    }

    fclose(f);
    return 0;
}