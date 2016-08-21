#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define ASCII_LOWER_START 97
#define ASCII_LOWER_END 122
#define ASCII_UPPER_START 65
#define ASCII_UPPER_END 90

/*
This program takes the users name as input.
It then outputs the initials of their name, capitalized.

Lachlan Cresswell 2016

*/

char charToUpper(char c);

int main(void)
{
    char* name = GetString();
    
    for(int i = 0;i < strlen(name); i ++)
    {
        //Convert character to ascii and check if it's a letter
        if(((int)name[i] >= ASCII_LOWER_START && name[i] <= ASCII_LOWER_END) || ((int)name[i] >= ASCII_UPPER_START && name[i] <= ASCII_UPPER_END))
        {
            //If it's the first character or is the first character after a space
            if(i == 0 || name[i-1] == ' ' )printf("%c", charToUpper(name[i]));
        }
    }
    printf("\n");
}

char charToUpper(char c)
{
    //If lowercase letter
    if((int)c >= ASCII_LOWER_START && (int)c <= ASCII_LOWER_END)return (char)((int)c)-(ASCII_LOWER_START-ASCII_UPPER_START);
        else return c;//Else leave it
}