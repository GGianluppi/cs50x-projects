#include "helpers.h"
#include <math.h>

BYTE cap_color(float color)
{
    if (color > 255)
    {
        return 255;
    }
    return round(color);
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // The function grayscale should take an image and turn it into a black-and-white version of the same image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            BYTE avg = round((float)(image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3);
            image[h][w].rgbtRed = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtBlue = avg;
        }
    }

}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // The function sepia should take an image and turn it into a sepia version of the same image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            RGBTRIPLE original_color = image[h][w];
            image[h][w].rgbtRed = cap_color(.393 * original_color.rgbtRed + .769 * original_color.rgbtGreen + .189 * original_color.rgbtBlue);
            image[h][w].rgbtGreen = cap_color(.349 * original_color.rgbtRed + .686 * original_color.rgbtGreen + .168 * original_color.rgbtBlue);
            image[h][w].rgbtBlue = cap_color(.272 * original_color.rgbtRed + .534 * original_color.rgbtGreen + .131 * original_color.rgbtBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // The reflect function should take an image and reflect ir horizontally
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            RGBTRIPLE tmp = image[h][(width - 1) - w];
            image[h][(width - 1) - w] = image[h][w];
            image[h][w] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Finally, the blur function shoul take an image and turn it into a box-blurred version of the same image.

    RGBTRIPLE new_image[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int count = 0, red = 0, green = 0, blue = 0;

            for (int aux_h = h - 1; aux_h <= h + 1; aux_h++)
            {
                if (aux_h < 0 || aux_h > height - 1)
                {
                    continue;
                }

                for (int aux_w = w - 1; aux_w <= w + 1; aux_w++)
                {
                    if (aux_w < 0 || aux_w > width - 1)
                    {
                        continue;
                    }
                    red += image[aux_h][aux_w].rgbtRed;
                    green += image[aux_h][aux_w].rgbtGreen;
                    blue += image[aux_h][aux_w].rgbtBlue;
                    count++;
                }
            }
            new_image[h][w].rgbtRed = cap_color((float) red / count);
            new_image[h][w].rgbtGreen = cap_color((float) green / count);
            new_image[h][w].rgbtBlue = cap_color((float) blue / count);
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = new_image[h][w];
        }
    }
}
