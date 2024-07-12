// Lab 08: C program to find integration using trapezoidal rule
#include "stdio.h"
#include "math.h"

#define f(x) (x + 2)
int main()
{
    float x0, xn, h, res;

    printf("Enter the Lower limit(i.e x0: ): ");
    scanf("%f", &x0);

    printf("Enter the upper limit(i.e xn: ): ");
    scanf("%f", &xn);

    h = (xn - x0);

    res = h * (f(x0) + f(xn)) / 2;

    printf("Integretion of f(x) is %.2f", res);

    return 0;
}