#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get name from user
    string name = get_string("What's your name: ");
    
    //print user's name and say Hello!
    printf("Hello, %s\n", name);
}

