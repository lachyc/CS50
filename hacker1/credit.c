#include <stdio.h>
#include <cs50.h>

int getCardProvider(long long i)
{
    //Get second digit
    while(i >= 100)i /= 10;
    i = i % 100;
    
    if(i == 33 || i == 37)
        return 1;//AmEx
    else if(i >= 51 && i <= 55)
        return 2;// MasterCard
    else if(i >= 40 && i <= 49)
        return 3;// Visa
    
    return -1;
}

int main(void)
{
    printf("Number: ");
    switch(getCardProvider(GetLongLong()))
    {
        case 1:
        printf("AMEX\n");
        break;
        
        case 2:
        printf("MASTERCARD\n");
        break;
        
        case 3:
        printf("VISA\n");
        break;
        
        default:
        printf("INVALID\n");
    }
}