#include <stdio.h>
#include <cs50.h>

long long getValidCardNumber()
{
    long long i = GetLongLong();
    while(i < 1000000000000 || i > 10000000000000000)
    {
        printf("You entered an incorrect number. Try again.\n");
        i = GetLongLong();
    }
    
    return i;
}

int getCardProvider(long long z)
{
    long long i = z;
    int x = 0;
    int y = 0;
    
    //Get second digit
    while(i >= 100)i /= 10;
    y = i % 10;
    
    //Get first digit
    while(i >= 10)i /= 10;
    x = i % 10;
    
    printf("First digit is %i\n", x);
    printf("Second digit is %i\n", y);
    
    //AmEx
    if(x == 3)
    {
        if(y == 3 || y == 7)return 1;
    }else if(x == 5){ // MasterCard
        if(y >= 1 && y <= 5)return 2;
    }else if(x == 4){ // Visa
        return 3;
    }
    
    return -1;
}

long long checkCreditCardNumber(long long x)
{
    
    int a, b, c, d;
    
    long long i = x;
    
    //14-digit or larger = all except some Visa
    if(x > 1000000000000)
    {
        while(i >= 100000000000000)i /= 10;
        a = i % 10;
        d = 14;
        printf("a: %i\n", a);
    }
    
    i = x;
    
    //15-digit = AmEx
    if(x > 100000000000000)
    {
        while(i >= 1000000000000000)i /= 10;
        b = i % 10;
        if(d < 15)d = 15;
        printf("b: %i\n", b);
    }
    
    i = x;
    
    //16-digit = MasterCard or Visa
    if(x > 1000000000000000)
    {
        while(i >= 10000000000000000)i /= 10;
        c = i % 10;
        printf("c: %i\n", c);
        
        if(d < 16)d = 16;
    }
    
    int numbers[d];
    if(d > 15)numbers[15] = c;
    if(d > 14)numbers[14] = b;
    if(d > 13)numbers[13] = a;
    
    
    
    i = x;
    
    //Get thirteenth digit
    while(i >= 10000000000000)i /= 10;
    numbers[12] = i % 10;
    
    //Get twelth digit
    while(i >= 1000000000000)i /= 10;
    numbers[11] = i % 10;
    
    //Get eleventh digit
    while(i >= 100000000000)i /= 10;
    numbers[10] = i % 10;
    
    //Get tenth digit
    while(i >= 10000000000)i /= 10;
    numbers[9] = i % 10;
    
    //Get ninth digit
    while(i >= 1000000000)i /= 10;
    numbers[8] = i % 10;
    
    //Get eigth digit
    while(i >= 100000000)i /= 10;
    numbers[7] = i % 10;
    
    //Get seventh digit
    while(i >= 10000000)i /= 10;
    numbers[6] = i % 10;
    
    //Get sixth digit
    while(i >= 1000000)i /= 10;
    numbers[5] = i % 10;
    
    //Get fifth digit
    while(i >= 100000)i /= 10;
    numbers[4] = i % 10;
    
    //Get fourth digit
    while(i >= 10000)i /= 10;
    numbers[3] = i % 10;
    
    //Get third digit
    while(i >= 1000)i /= 10;
    numbers[2] = i % 10;
    
    //Get second digit
    while(i >= 100)i /= 10;
    numbers[1] = i % 10;
    
    //Get first digit
    while(i >= 10)i /= 10;
    numbers[0] = i % 10;
    
    int final = 0;
    int var;
    int index;
    int length = sizeof(numbers) / sizeof(numbers[0]);
    printf("array is %i long\n", length);
    
    printf("Getting evens...\n");
    
    for(int y = 1;y<(length/2)+1;y++)
    {
        index = (y*2)-1;
        var = numbers[index]*2;
        if(var > 9)
        {
            //Get first digit
            while(var >= 10)var /= 10;
            var = var % 10;
            final += var;
            var = numbers[index]*2-10;
        }
        final += var;
        printf("index %i is %i\n", index, var);
    }
    
    printf("final: %i", final);
    
    printf("Getting odds...\n");
    
    for(int y = 1;y<(length/2)+2;y++)
    {
        index = (y*2)-2;
        if(index > 15)break;
        var = numbers[index];
        final += var;
        printf("index %i is %i\n", index, var);
    }
    
    printf("Checksum: %i\n", final);
    
    //Get second digit
    while(final >= 100)i /= 10;
    final = final % 10;
    
    printf("digit two: %i\n", final);
    if(final == 0)
    {
        return 1;
    }
    
    return -1;
}

int main(void)
{
    printf("Hey! This is my 'Credit Card Check' app for CS50.\nIt will tell you some info about your credit card and order automatically order a bunch of pocket-pussies to your doorstep :)\n");
    printf("What is your card number?\n");
    
    printf("Number: ");
    
    long long i = getValidCardNumber();
    
    int x = getCardProvider(i);
    int y = checkCreditCardNumber(i);
    
    if(x > 0)
    {
        if(y > 0)
        {
            
            if(x == 1)printf("AMEX\n");
            if(x == 2)printf("MASTERCARD\n");
            if(x == 3)printf("VISA\n");
        }else{
            printf("INVALID\n");
        }
    }else{
        printf("The number you have provided is not valid.\n");
        printf("INVALID\n");
    }
    
    return 0;
    
}