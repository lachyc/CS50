#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define ASCII_LOWER_START 97
#define ASCII_LOWER_END 122
#define ASCII_UPPER_START 65
#define ASCII_UPPER_END 90

#define ASCII_0 48
#define ASCII_9 57

#define KEY 13

/*
This program takes a word or sentence as input.

It outputs the sentence as encrypted via a caesar cypher.

Lachlan Cresswell 2016

*/

int isLetter(char c);
int strToInt(char c[]);
int powerOf(int x, int p);

int main(int argc, char *argv[])
{
    if(argc > 2 || argc < 2)return 1;
    
    int key = strToInt(argv[1]);
    
    char* s = GetString();
    
    char* c;
    
    for(int i = 0;i < strlen(s); i ++)
    {
        if(isLetter(s[i]))
        {
            c = (char*)((int)s[i]+KEY);
            if((int)c > ASCII_LOWER_END || ((int)c > ASCII_UPPER_END) && (int)c < ASCII_LOWER_START)c = (char*)(int)c-(26);
            //printf("%c", s[i]);
            printf("%c", c);
        }
    }
    
    //printf("%s", argv[2]);
    printf("\n");
}

int isLetter(char c)
{
    if(((int)c >= ASCII_LOWER_START && (int)c <= ASCII_LOWER_END) || ((int)c >= ASCII_UPPER_START && (int)c <= ASCII_UPPER_END))return 1;
    
    return 0;
}

int strToInt(char c[])
{
    int x;
    int y = strlen(c);
    printf("%i\n", powerOf(10, 0));
    printf("%i\n", powerOf(10, 1));
    printf("%i\n", powerOf(10, 2));
    for(int i = 0;i < strlen(c);i ++)
    {
        //Cast to int to check against ASCII table
        if((int)c[i] >= ASCII_0 && (int)c[i] <= ASCII_9)
        {
            printf("char: %c\n", c[i]);
            printf("int: %i\n", (int)c[i]-ASCII_0);
            x += ((int)c[i]-ASCII_0)*(powerOf(10, y));
            printf("x: %i\n", x);
        }
        
        y --;
        
    }
    
    return -1;
}

int powerOf(int x, int p)
{
    if(p == 0)return 1;
    for(int i = 1; i < p; i ++)
    {
        x = x*x;
    }
    
    return x;
}