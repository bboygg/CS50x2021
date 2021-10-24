#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declare the variable for height value
    int height;
    
    do 
    {
        //prompt user to get height
        height = get_int("Height: ");
    }
    //Iterate from 1 to 8
    while (height < 1 || height > 8);
    
    //Iterate til height 
    for (int i = 0 ; i < height ; i++)
    {
        //print space to right alignment
        for (int j = 0 ; j < height - i - 1 ; j++)
        {
            printf(" ");
        }
        //print hash to make pyramid
        for (int k = 0 ; k < i + 1 ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}