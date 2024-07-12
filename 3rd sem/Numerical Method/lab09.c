// Lab 09: C program to calculate the numerical integration using composite trapezoidal rule
#include "stdio.h"

#define f(x) (1 / (1 + (x * x)))
#define MAX 20

int main()
{
    float y[MAX], h, x0, xn, res = 0;
    int n;

    printf("Enter the lower limit: ");
    scanf("%f", &x0);

    printf("Enter the upper limit: ");
    scanf("%f", &xn);

    printf("Enter the number of segments(max 19): ");
    scanf("%d", &n);

    h = (xn - x0) / n;
    for (int i = 0; i <= n; i++)
    {
        y[i] = f(x0 + i * h);
    }

    for (int i = 1; i < n; i++)
    {
        res += 2 * y[i];
    }

    res += y[0] + y[n];

    printf("Numerical integration for f(x): %.2f", res * h / 2);

    return 0;
}