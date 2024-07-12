// Lab 04: c program to find the root of a non linear equation using fixed point iteration method.
#include "stdio.h"
#include "math.h"

#define g(x) cbrt(4 * x + 9)

void fixedPointMethod(float, float);

int main()
{
    float x0, err;

    printf("Enter the values:\n");

    printf("x0: ");
    scanf("%f", &x0);

    printf("stopping criteria(0-1): ");
    scanf("%f", &err);
    fixedPointMethod(x0, err);

    return 0;
}

void fixedPointMethod(float x0, float err)
{
    float x1, e = 1;

    while (e > err)
    {
        x1 = g(x0);

        e = fabs((x1 - x0) / x1);

        x0 = x1;
    }

    printf("Root of the function: %.4f", x1);
}