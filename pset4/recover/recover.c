#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if the arguments passed are as expected

    // Open memery card and save the content into a file
    FILE *f = fopen(card, 'r');
    if (f == NULL)
    {
        perror("Error in opening file");
        return (1);
    }

    // Scan the card file and recover JPEG files

        // Iterate over blocks of 512 bytes
        int j = 0;
        while (1)
        {
            // Check if at the end of the file
            if (feof(f))
            {
                printf("End of file.");
                break;
            }
                // Find the 1st block in the file

                // Check if the beginning of the block has 0xff 0xd8 0xff (0xe0 upto 0xef)
                int *buff = malloc(sizeof(int) * 512);
                fread(buff, sizeof(int), 512, f);

                buff[0] == 0xff;
                buff[0] == 0xd8;
                buff[0] == 0xff;
                (buff[3] & 0xf0) == 0xe0;

                // If yes Open (create) new file
                char filename[8];
                sprintf(filename, '%03d.jpg', j);

                // Write the content to the opened file
                fwrite(buff, sizeof(int), 512, filename);

                // Move to the next block

            // Go back to begining of the while loop  and repeat
            j += 1;
        }
    // Close the card file
    fclose(f);

return(0);
}
