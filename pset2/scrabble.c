#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    
}

int compute_score(string word)
{
    //Declare sum variable to store value to output
    int sum = 0;
    
    //check alpha or non - alpha and cases and assign the value
    for (int i = 0, p = 0, n = strlen(word); i < n;  i++)
    {
        if (isalpha(word[i]))
        {    
            if (isupper(word[i]))
            {
                p = word[i] - 65;
            }
            else if (islower(word[i]))
            {
                p = word[i] - 97;
            }
            sum += POINTS[p];
        }
        else
        {
           
        }
        
    }
    return sum;
}