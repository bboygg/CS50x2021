#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    //prompt to get User Input
    string text = get_string("Text: ");

    //Declare the var which include num of elements in text.
    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sentences = count_sentences(text);

    //calcualte index
    float L = num_letters / (float)num_words * 100;
    float S = num_sentences / (float)num_words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}


int count_letters(string text)
{
    int letters = 0;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else
        {

        }
    }
    return letters;
}

int count_words(string text)
{
    //At the end of the word in the sentence does not have space, so that set initial value as '1'
    int words = 1;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == 32)
        {
            words ++;
        }
        else
        {

        }
    }
    return words;
}


int count_sentences(string text)
{
    
    int sentences = 0;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences ++;
        }
        else
        {

        }
    }
    return sentences;
}
