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

    // End of the file
    fseek(fs, 0, SEEK_END);
    // How many blocks of 512 bytes
    int nb = ftell(fs) / 512;
    printf("nb = %d\n", nb);

    // Initialise array where we shall store marks of where the jpeg fils start
    int *marks;

    // Get back to the beginnig of the file
    fseek(fs, 0, SEEK_SET);

    // Iterate over blocks of 512 bytes
    for (int i = 0; i < 200; ++i)
    {
        // Check if the beginning of the block has 0xff 0xd8 0xff (0xe0 upto 0xef)
        int *buff = malloc(512);
        if (buff == NULL)
        {
            printf("Error allocating memroy\n");
            return 1;
        }
        // Load 512 bytes into a buffer
        fread(buff, 1, 512, fs);
        
        printf("i = %d, position = %ld, buff[0] = %x \n", i, ftell(fs), buff[0]);

        if (buff[0] == 0xff &&
            buff[1] == 0xd8 &&
            buff[2] == 0xff &&
            (buff[3] & 0xf0) == 0xe0)
        {
            // Rercord the position to the marks array
            fseek(fs, 0, SEEK_CUR);
            marks = realloc(marks, sizeof(int) + (i * sizeof(int)));
            marks[i] = ftell(fs);
        }
        free(buff);
        // Go to the next block in the file
        fseek(fs, 512, SEEK_CUR);
    }

    // Close the card file
    fclose(fs);
    free(marks);

return 0;
}
