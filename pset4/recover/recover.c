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


return 0;
}
