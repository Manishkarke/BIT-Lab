// Lab 08: C program to implement Tower Of Hanoi algorithm recursively
#include "stdio.h"

void TOH(int, char, char, char);

int main()
{
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);

    TOH(num, 'A', 'B', 'C');

    return 0;
}

// Tower Of Hanoi Algorithm
void TOH(int n, char src, char aux, char des)
{
    if (n == 1)
    {
        printf("Disk %d moved from %c to %c.\n",n, src, des);
    }
    else
    {
        TOH(n - 1, src, des, aux);
        printf("Disk %d moved from %c to %c.\n", n, src, des);
        TOH(n - 1, aux, src, des);
    }
}