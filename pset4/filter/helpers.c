#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;

    for (int h = 0; h < width; h++)
    {
        for (int w = 0; w < width; w ++)
        {
            avg = (int)(image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed)/3;
            image[h][w].rgbtBlue = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
