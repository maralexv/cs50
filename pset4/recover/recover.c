#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if the arguments passed are as expected

    // Open memery card
    FILE *f = fopen(card, 'r');

    // Scan card and recover JPEG files

        // Look for JPEG files and recover them

            // Iterate over blocks of 512 bytes
            int j = 0;
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

            // Move to the next block, check if the end of card

            // Go back to check if JPEG, then Close the open file  and repeat

    // Close the program
    fclose(f);

}
