#include <stdio.h>
#include <string.h>
#include <cs50.h>

/*
This program takes a DES-based encrypted 8 character long password as input.

It outputs the decrypted password.

Lachlan Cresswell 2016

*/


int main(int argc, char *argv[])
{
    char* pw = GetString();
    
    if(argc > 2 || argc < 2)return -1;
    
    
    printf("\n");
}