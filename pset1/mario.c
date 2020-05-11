// Build symmetrical pyramids using bricks
#include<stdio.h>
#include<cs50.h>

// Introducing funcs, used in main
int ask(void);
int pyramids(int hight);
int build_layer(int n, int width);
int lay_brick(void);
int keep_void(void);

// Main block, where the program starts
int main(void)
{

}

// Ask user for input - hight of puyramids (number of bricks)
int ask(void)
{
    int num;
    do
    {
        num = get_int("How many bricks tall do you want the pyramids to be? ");
    }
    while (num < 1);
    return num;
}

// Build 2 symmetric pyramids
int pyramids(int hight)
{
    for (int i = 1; i < hight; i++)
    {
        build_layer(i, hight);
    }
}

// Build one layer of the pyramid
int build_layer(int n, int width)
{
    int n_bricks = n;
    int n_voids = width - n;

}

// Lay a brick
int lay_brick(void)
{
    printf("#");
}

// Keep the void
int keep_void(void)
{
    printf(" ");
}