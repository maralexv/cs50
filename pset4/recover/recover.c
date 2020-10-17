#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if the arguments passed are as expected
    if (argc != 2)
    {
        printf("Usage: ./recver card.row\n");
        return 1;
    }
    // Open memery card for reading
    FILE *fs = fopen(argv[1], "r");
    if (fs == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Scan the card file and recover JPEG files

        // Get to the beginnig of the file
        fseek(fs, 0, SEEK_SET);

        // Iterate over blocks of 512 bytes
        int i = 0;
        int j = 0;
        while (1)
        {
            // Check if at the end of the file and stop the loop if true
            if (feof(fs))
            {
                printf("End of file\n");
                break;
            }
                // Go to the i-th block in the file
                fseek(fs, (i * 512), SEEK_SET);

                // Check if the beginning of the block has 0xff 0xd8 0xff (0xe0 upto 0xef)
                int *buff = malloc(sizeof(char) * 512);
                fread(buff, sizeof(char), 512, fs);

                if (buff[0] == 0xff &&
                    buff[1] == 0xd8 &&
                    buff[2] == 0xff &&
                    (buff[3] & 0xf0) == 0xe0)
                {
                    // If true Open (create) new file for appending
                    ++j;
                    char filename[8];
                    sprintf(filename, "%03d.jpg", j);
                    FILE *fd = fopen(filename, "a");
                    if (fd == NULL)
                    {
                        printf("Error creating new file");
                        return (1);
                    }
                    // Write the content of the block in buffer to the opened file
                    fwrite(buff, sizeof(char), 512, fd);
                    fclose(fd);
                    free(buff);
                }
                
                if (j > 0)
                {
                    char filename[8];
                    sprintf(filename, "%03d.jpg", j);
                    // Open fd file to append
                    FILE *fd = fopen(filename, "a");
                    if (fd == NULL)
                    {
                        printf("Error creating new file");
                        return (1);
                    }
                    // Write the content of the block in buffer to the opened file
                    fwrite(buff, sizeof(int), 512, fd);
                    fclose(fd);
                }

            // Go back to begining of the while loop  and repeat
            ++i;
        }

    // Close the card file
    fclose(fs);

return 0;
}
