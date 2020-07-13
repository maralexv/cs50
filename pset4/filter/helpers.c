#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            int avg = roundf((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed)/3);
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
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            int sepRed = roundf((0.189 * image[h][w].rgbtBlue) + (0.769 * image[h][w].rgbtGreen) + (0.393 * image [h][w].rgbtRed));
            int sepGreen = roundf((0.168 * image[h][w].rgbtBlue) + (0.686 * image[h][w].rgbtGreen) + (0.349 * image[h][w].rgbtRed));
            int sepBlue = roundf((0.131 * image[h][w].rgbtBlue) + (0.534 * image[h][w].rgbtGreen) + (0.272 * image[h][w].rgbtRed));

            if (sepRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = sepRed;
            }

            if (sepGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = sepGreen;
            }

            if (sepBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = sepBlue;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    int mid;
    
    if (width % 2 == 0)
    {
        mid = width/2;
    }
    else
    {
        mid = width/2 + 1;
    }

    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < mid; ++w)
        {
            tmp = image[h][w];
            image[h][w] = image[h][width - w];
            image[h][width - w] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
