#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if the arguments passed are as expected
    if (argc != 2)
    {
        printf("Usage: ./recver card.row\n");
        return 1;
    }

    // Open a file and read card content into it
    FILE *sourcefile = fopen(argv[1], "r");
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
        fread(b, 1, 512, sourcefile);

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
                fwrite(b, 1, 512, targetfile);
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
                fwrite(b, 1, 512, targetfile);
            }
        }

        // When a target jpg file is already open
        if (i > -1)
        {
            // Write b block to the current .jpg file
            fwrite(b, 1, 512, targetfile);
        }

    }

    // Free dynamically allocated memry
    free(b);

    // Close all open files and exit
    fclose(targetfile);
    fclose(sourcefile);
    return 0;
}
