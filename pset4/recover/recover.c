#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if the arguments passed are as expected
    if (argc != 1)
    {
        printf("Usage: ./recver card.row\n");
        return (1);
    }
    // Open memery card for reading
    FILE *f = fopen(argv[0], 'r');
    if (f == NULL)
    {
        printf("Error opening file");
        return (1);
    }

    // Scan the card file and recover JPEG files

        // Get to the beginnig of the file
        fseek(f, 0, SEEK_SET);

        // Iterate over blocks of 512 bytes
        int i = 0;
        int j = 0;
        while (1)
        {
            // Check if at the end of the file
            if (feof(f))
            {
                printf("End of fileß");
                break;
            }
                // Go to the i-th block in the file
                fseek(f, (i * 512), SEEK_SET);

                // Check if the beginning of the block has 0xff 0xd8 0xff (0xe0 upto 0xef)
                int *buff = malloc(sizeof(int) * 512);
                fread(buff, sizeof(int), 512, f);

                if (buff[0] == 0xff &
                    buff[1] == 0xd8 &
                    buff[2] == 0xff &
                    (buff[3] & 0xf0) == 0xe0)
                {
                    // If true Open (create) new file for appending
                    j += 1;
                    char filename[8];
                    sprintf(filename, '%03d.jpg', j);
                    FILE *filename = fopen(filename, 'a');
                    if (filename == NULL)
                    {
                        printf("Error creating new file");
                        return (1);
                    }
                    // Write the content of the block in buffer to the opened file
                    fwrite(buff, sizeof(int), 512, filename);
                    // Move to the end of the block 
                    fseek(filename, 512, SEEK_CUR);
                }
                
                if (j > 0)
                {
                    char filename[8];
                    sprintf(filename, '%03d.jpg', j);
                    // Write the content of the block in buffer to the opened file
                    fwrite(buff, sizeof(int), 512, filename);
                    // Move to the end of the block
                    fseek(filename, 512, SEEK_CUR);
                }
                

            // Go back to begining of the while loop  and repeat
            i += 1;
        }
    // Close the card file
    fclose(f);

return (0);
}
