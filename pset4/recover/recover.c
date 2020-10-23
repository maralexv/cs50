#include<stdio.h>
#include <stdlib.h>

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

    fseek(sourcefile, 0, SEEK_END);
    unsigned long end = ftell(sourcefile);
    
    // Allocate memry for a buffer
    BYTE *b = malloc(512);
    if (b == NULL)
    {
        fclose(sourcefile);
        printf("Error allocating memory for buffer!\n");
        return 2;
    }

    // Get to the very begining of the file and scan it
    fseek(sourcefile, 0, SEEK_SET);

    // Loop through the sourcefile by chuncks of 512 bytes
    do
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
                y = 1; //First image found!
                // Crete new .jpg file and open for append
                sprintf(filename, "%03i.jpg", i);
                targetfile = fopen(filename, "a");
                if (!targetfile)
                {
                    fclose(sourcefile);
                    fclose(targetfile);
                    printf("Error creating the 1st file!\n");
                    return 3;
                }
                // Write b block into new .jpeg file
                fwrite(b, sizeof(BYTE), 512, targetfile);
                fclose(targetfile);
            }

            // If not the 1st jpg header found
            else
            {
                // Create new .jpg file and open for append
                sprintf(filename, "%03i.jpg", i++);
                targetfile = fopen(filename, "a");
                if (!targetfile)
                {
                    fclose(sourcefile);
                    fclose(targetfile);
                    printf("Error creating new file!\n");
                    return 4;
                }
                // Write b block into new .jpeg file
                fwrite(b, sizeof(BYTE), 512, targetfile);
                fclose(targetfile);
            }
        }

        // When a target jpg file already exists
        if (y)
        {
            sprintf(filename, "%03i.jpg", i);
            targetfile = fopen(filename, "a");
            if (!targetfile)
            {
                fclose(sourcefile);
                fclose(targetfile);
                printf("Error openning target file!\n");
                return 5;
            }
            // Write b block to the current .jpg file
            fwrite(b, sizeof(BYTE), 512, targetfile);
            fclose(targetfile);
        }

    } while (ftell(sourcefile) < end);

    // Garbage collection
    // Free dynamically allocated memry
    free(b);
    // Close all open files and exit
    fclose(targetfile);
    fclose(sourcefile);
    return 0;
}
