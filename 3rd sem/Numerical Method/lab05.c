// Lab 05: C program to find the imterpolation at given point.
#include "stdio.h"
#include "math.h"
#define MAX_SIZE 20

void lagrangesMethod(float[], float[], float, int);

int main()
{
    float x[MAX_SIZE], fx[MAX_SIZE], X;
    int n;

    printf("Enter the number of data points(max: 19): ");
    scanf("%d", &n);

    printf("Enter Values for x:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter values for f(x):\n");
    for (int i = 0; i < n; i++)
    {
        printf("f(x[%d]): ", i);
        scanf(" %f", &fx[i]);
    }

    printf("Enter the value of x for which you want to find f(x): ");
    scanf("%f", &X);

    lagrangesMethod(x, fx, X, n);
}

void lagrangesMethod(float x[], float fx[], float X, int n)
{
    float mul, sum = 0;

    for (int i = 0; i < n; i++)
    {
        mul = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                mul *= (X - x[j]) / (x[i] - x[j]);
            }
        }
        sum += mul * fx[i];
    }
    printf("the function value at x = %.3f is %.3f", X, sum);
}