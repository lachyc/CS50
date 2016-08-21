#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 4;
    int x = 6;
    int y = &n;
    int *pointer_to_n = &n;
    int **ppointer = pointer_to_n;
    
    printf("n's value is %i \n", n);
    printf("n's address is %i \n", &n);
    printf("x's value is %i \n", x);
    printf("x's address is %i \n", &x);
    printf("y's value is %i \n", y);
    printf("pointer's address is %i \n", &pointer_to_n);
    printf("pointer's value is %i \n", pointer_to_n);
    printf("pointer's dereferenced value is %i \n", *pointer_to_n);
    printf("\n\n");
    
    //pointer_to_n ++;
    (pointer_to_n) = y;
    
    
    printf("n's value is %i \n", n);
    printf("n's address is %i \n", &n);
    printf("x's value is %i \n", x);
    printf("x's address is %i \n", &x);
    printf("y's value is %i \n", y);
    printf("pointer's address is %i \n", &pointer_to_n);
    printf("pointer's value is %i \n", pointer_to_n);
    printf("pointer's dereferenced value is %i \n", *pointer_to_n);
    printf("\n\n");
    
}