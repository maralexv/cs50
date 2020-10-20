#include<stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("card.raw", "r");
    if (!f)
    {
        printf("Error reading the file\n");
        return 1;
    }

    fseek(f, 0, SEEK_SET);

    int i = -1;
    while (1)
    {
        if (feof(f))
        {
            break;
        }

        unsigned char *b = malloc(512);
        if (b == NULL)
        {
            printf("Error!");
            return 2;
        }
        fread(b, 1, 512, f);

        if (b[0] == 0xff && 
            b[1] == 0xd8 && 
            b[2] == 0xff && 
            (b[3] & 0xf0) == 0xe0)
        {
            if (i < 1)
            {
                ++i;
                long int start = ftell(f);
                // Crete new .jpg file and open for append
                char filename[8];
                sprintf(filename, "%03i.jpg", i);

                // Write b block into new .jpeg file

                // for testing
                printf("%s, start: %ld\n", filename, start);
            }
            else
            {
                // Close the previouse .jpg file 

                // Create new .jpg file and open for append

                // Write b block into new .jpg file
            }
        }

        if (i != -1)
        {
            // Write b block to the current .jpg file
        }

        free(b);
    }

    fclose(f);
    return 0;
}

/*
FILE *img = fopen(filename, "w");
fwrite(data, size, number, file);
*/