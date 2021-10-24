#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollors;
    
    //prompt user to input float value
    do
    {
        dollors = get_float("Change owed: ");
    }
    while (dollors < 0);
    
    
    //convert dollor to cent
    int cents = round(dollors * 100);
    int coins = 0;
    
    //start greedy algorithms!!!
    //quarter
    while (cents >= 25)
    {
        cents -= 25;
        coins ++;
    }
    
    //dime
    while (cents >= 10)
    {
        cents -= 10;
        coins ++;
    }
    
    //nickel
    while (cents >= 5)
    {
        cents -= 5;
        coins ++;
    }
    
    //penny
    while (cents >= 1)
    {
        cents -= 1;
        coins ++;
    }
    
    //print number of coins
    print("{coins}");
    
    
}