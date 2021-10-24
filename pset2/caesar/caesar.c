#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


string encrypt(string plaintext, int key);

//only accept single command line argument and non -negative integer, if not print error message 
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error with command line argument\n");
        return 1;
    }
    else
    {
        for (int i = 0 ; i < strlen(argv[1]) ; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        
        int key = atoi(argv[1]); // Declare key variable to run function.
        
        
        string plaintext = get_string("plaintext:   "); //prompt use to input plantext and store it to var
        
        plaintext = encrypt(plaintext, key);

        printf("ciphertext: %s\n", plaintext);
        return 0;
        
    }
    

}


string encrypt(string plaintext, int key)
{
    key = key % 26;
    
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            plaintext[j] = (plaintext[j] - 65 + key) % 26;
                
            plaintext[j] += 65;
        }
        else if (islower(plaintext[j]))
        {
            plaintext[j] = (plaintext[j] - 97 + key) % 26;
                
            plaintext[j] += 97;
        }
    }
        
    return plaintext;
}
