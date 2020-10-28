#include<stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

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
        printf("Error reading the file!`\n");
        return 1;
    }

    // Initialise variables to be used in while loop
    int i = 0; // Images counter
    int y = 0; // Flag of 1st image fohnd
    char filename[8]; // Image name
    FILE *targetfile = NULL; // Target file to store images
    
    // Allocate memry for a buffer
    BYTE *b = malloc(512);
    if (b == NULL)
    {
        fclose(sourcefile);
        printf("Error allocating memory for buffer!\n");
        return 2;
    }

    // Find out hoe many blocks of 512 BYTES are on card
    fseek(sourcefile, 0, SEEK_END);
    unsigned long q = ftell(sourcefile) / 512;

    // Get to the very begining of the file and scan it
    fseek(sourcefile, 0, SEEK_SET);

    // Loop through the sourcefile by chuncks of 512 bytes
    for (int n = 0; n < q; n++)
    {
        // Read 512 - byte block into buffer
        fread(b, sizeof(BYTE), 512, sourcefile);

        // Check the header of the block to see whether it is .jpg file header
        if (b[0] == 0xff && 
            b[1] == 0xd8 && 
            b[2] == 0xff && 
            (b[3] & 0xf0) == 0xe0)
        {
            // If first jpg header found
            if (!y)
            {
                // Crete first .jpg file name
                sprintf(filename, "%03i.jpg", i);
                //First image found!
                y = 1; 
            }

            // If not the 1st jpg header found
            else
            {
                // Increase image count by 1
                i++;
                // Create new .jpg file name
                sprintf(filename, "%03i.jpg", i);
            }
        }

        // If firsdt jpg file has already been found
        // Write blocks of 512 bytes using current filename
        if (y)
        {
            // Create )if does not exist) and open gilename.jpg file 
            targetfile = fopen(filename, "a");
            if (!targetfile)
            {
                fclose(sourcefile);
                fclose(targetfile);
                printf("Error openning target file!\n");
                return 5;
            }
            // Write b block to the current filename.jpg file
            fwrite(b, sizeof(BYTE), 512, targetfile);
            fclose(targetfile);
        }
    }

    // Garbage collection
    // Free dynamically allocated memry
    free(b);
    // Close all files and exit
    fclose(targetfile);
    fclose(sourcefile);
    return 0;
}
