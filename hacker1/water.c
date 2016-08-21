#include <stdio.h>
#include <cs50.h>

int getPosInt()
{
    int i = GetInt();
    while(i < 1)
    {
        printf("You entered a number less than 1. Try again.\n");
        i = GetInt();
    }
    
    return i;
}

int main(void)
{
    printf("Hey! This is my 'Smart Water' app for CS50.\nIt will tell you how many 16oz bottles of water you use during your shower.\n");
    printf("How long does your average show take in minutes?\n");
    
    int i = getPosInt();
    
    if(i > 0)
    {
        printf("Your %i minute shower uses %ioz which is %i bottles of water.\n", i, i*192, (i*192)/16);
        if(i > 10)printf("Fix ya shower time, mate!\n");
    }
}