#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = -1;
    
    while(i > 23 || i < 0)
    {
        printf("Enter a non-negative integer < 24: ");
        i = GetInt();
    }
    
    int space = 2;
    int z;
    for(int x = 1;x <= i;x ++)//Vertical
    {
        z = i-x;
        for(int y = 0;y < i+space+x;y ++)//Horizontal
        {
            if(y < z+x && y >= z)printf("#");
                else if(y >= i+space && y < i+space+x)printf("#");
                else printf(" ");
        }
        
        //printf("  x: %i", x);
        //printf("  z: %i", z);
        printf("\n");
    }
    
}