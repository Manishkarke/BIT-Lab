// Lab 06: C program to find factorial of a given number recursively
#include "stdio.h"

int fact(int);

int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial of negative number cannot be found.");
    else
        printf("The factorial of %d is %d.", num, fact(num));
}

// Function to calculate recursive function
int fact(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * fact(num - 1);
}