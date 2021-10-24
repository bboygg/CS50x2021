#include "helpers.h"
#include <math.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int average = round((red + green + blue) / 3); 

            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
    for (int i= 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            
            //calculate sepia filter value  
            float red = .393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue;
            float green = .349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue;
            float blue = .272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue;
            
            int sepiaRed = round(red);
            int sepiaGreen = round(green);
            int sepiaBlue = round(blue);
            
            //validation check to make cap to 255
           
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
                
            }
            
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
                
            }
            
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
        
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
            
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_red = 0;
            float sum_green = 0;
            float sum_blue = 0;
            int counter = 0;
            
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    if(j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    
                    sum_red += temp[i + k][j +l ].rgbtRed;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    counter++;
                }
            }
            
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
        
    }
    
    return;
}

