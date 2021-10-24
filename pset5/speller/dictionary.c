// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const int N = 10000;
// Hash table
node *table[N];

int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    //Hash word to obtain hash value
    int hash_value = hash(word);

    //Access linked list at that index in hash table

    node *n = table[hash_value];

    //Traverse linked list, loooking for word (strcasecomp)
    while ( n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        else
        {
            n = n->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    //Funtion should take a string and return an index
    // This hash function adds the ASCII values of all characters in the word together.
    int value = 0;

    for (int i = 0; i < strlen(&word[i]); i++)
    {
        value += tolower(*word);
    }

    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open up this dictionary file
    FILE *dict_pointer = fopen(dictionary, "r");

    // Check if null
    if (dict_pointer == NULL)
    {
        printf("Unable to open  %s\n", dictionary);
        unload();
        return 1 ;
    }

    //Initialise word array
    char next_word[LENGTH + 1];

    //Read strings from file one at a time, loop will run until fscnaf return EOF
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        //Create new node for each word
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            unload();
            return 2;
        }

        //copyword into node using strcpy
        strcpy(n->word, next_word);

        //Hash word to obtain hash value
        int hash_value = hash(next_word);

        //Insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }

    //Close file
    fclose(dict_pointer);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //Iterate over hash table and free nodes in each linked list
    for(int i = 0; i < N; i++)
    {
        //Assign cursur
        node *n = table[i];

        //Loop through linked list
        while (n != NULL)
        {
            //Make temp equal cursur
            node *tmp = n;
            //Point cursur to next element
            n = n->next;
            //free temp
            free(tmp);
        }

        if (n == NULL && i == N - 1)
        {
            return true;
        }

    }

    return false;
}
