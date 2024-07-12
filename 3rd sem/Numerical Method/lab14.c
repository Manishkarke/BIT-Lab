// Lab 14: C program to find the numerical integration of a function using gaussian integration
#include "stdio.h"

#define f(x) 1 / (1 + x * x)

int main()
{
    float z1, z2, c1, c2, a, b, res = 0.0, x1, x2;

    c1 = c2 = 1;
    z1 = -0.57735;
    z2 = -z1;

    printf("Enter the lower limit: ");
    scanf("%f", &a);

    printf("Enter the upper limit: ");
    scanf("%f", &b);

    x1 = (b - a) / 2 * z1 + (b + a) / 2;
    x2 = (b - a) / 2 * z2 + (b + a) / 2;

    res = (b - a) / 2 * (c1 * (f(x1)) + c2 * (f(x2)));
    printf("Numerical integration for f(x): %.3f", res);

    return 0;
}