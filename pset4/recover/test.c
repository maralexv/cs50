#include<stdio.h>
#include <stdlib.h>

int main()
{
    // Open a file and read card content into it
    FILE *sourcefile = fopen("card.raw", "r");
    if (!sourcefile)
    {
        printf("Error reading the file\n");
        return 1;
    }

    // Initialise variables to be used in while loop
    int i = -1;
    char filename[8];
    FILE *targetfile;
    // Allocate memry for a buffer
    unsigned char *b = malloc(512);
    if (b == NULL)
    {
        printf("Error!");
        return 2;
    }

    // Get to the very begining of the file and scan it
    fseek(sourcefile, 0, SEEK_SET);
    while (1)
    {
        // Break out of wjile loop if end of file is reached
        if (feof(sourcefile))
        {
            break;
        }

        // Read 512 - byte block into buffer
        printf("s %ld ", ftell(sourcefile));
        fread(b, 1, 512, sourcefile);
        printf("%ld\n", ftell(sourcefile));

        // Check the header of the block to see whether it is .jpg file header
        if (b[0] == 0xff && 
            b[1] == 0xd8 && 
            b[2] == 0xff && 
            (b[3] & 0xf0) == 0xe0)
        {
            // If first jpg header found
            if (i < 0)
            {
                // Crete new .jpg file and open for append
                ++i;
                sprintf(filename, "%03i.jpg", i);
                targetfile = fopen(filename, "a");
                if (!targetfile)
                {
                    printf("Error creating the file\n");
                    return 3;
                }
                // Write b block into new .jpeg file
                printf("t %ld", ftell(targetfile));
                fwrite(b, 1, 512, targetfile);
                printf(" %ld\n", ftell(targetfile));
            }

            // If not the 1st jpg header found
            else
            {
                // Close the previouse .jpg file
                fclose(targetfile);
                // Create new .jpg file and open for append
                ++i;
                sprintf(filename, "%03i.jpg", i);
                targetfile = fopen(filename, "a");
                if (!targetfile)
                {
                    printf("Error creating the file\n");
                    return 3;
                }
                // Write b block into new .jpeg file
                printf("t %ld", ftell(targetfile));
                fwrite(b, 1, 512, targetfile);
                printf(" %ld\n", ftell(targetfile));
            }
        }

        // When a target jpg file is already open
        if (i > -1)
        {
            // Write b block to the current .jpg file
            printf("t %ld", ftell(targetfile));
            fwrite(b, 1, 512, targetfile);
            printf(" %ld\n", ftell(targetfile));
        }

    }

    // Free dynamically allocated memry
    free(b);

    // Close all open files and exit
    fclose(targetfile);
    fclose(sourcefile);
    return 0;
}
