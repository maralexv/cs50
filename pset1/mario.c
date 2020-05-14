// Build symmetrical pyramids using bricks
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>

// Introducing funcs, used in main
int ask(void);
int build_pyramids(int hight);
int build_layer(int n, int width);
int lay_brick(void);
int keep_void(void);

// Main block, where the program starts
int main(void)
{
    int p_hight = ask();
    build_pyramids(p_hight);
}

// Ask user for input - hight of puyramids (number of bricks)
int ask(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num < 1 || num > 8);

    return num;
}

// Build 2 symmetric pyramids
int build_pyramids(int hight)
{
    for (int i = 1; i <= hight; i++)
    {
        build_layer(i, hight);
    }
    return 0;
}

// Build one layer of the pyramid
int build_layer(int n, int width)
{
    int n_bricks = n;
    int n_voids = width - n;

    // Voids in left pyramid
    for (int i = 0; i < n_voids; i++)
    {
        keep_void();
    }

    // Bricks in left pyramid
    for (int i = 0; i < n_bricks; i++)
    {
        lay_brick();
    }

    // Gap between pyramids
    printf("  ");

    // Bricks in right pyramid
    for (int i = 0; i < n_bricks; i++)
    {
        lay_brick();
    }

    printf("\n");
    return 0;
}

// Lay a brick
int lay_brick(void)
{
    printf("#");
    return 0;
}

// Keep the void
int keep_void(void)
{
    printf(" ");
    return 0;
}
