// Lab 10: C program to find numerical integration using simpson 1/3 rule.
#include "stdio.h"

#define f(x) (1 / (1 + x))
// #define MAX 2

int main()
{
    float h, x0, xn, res = 0;
    int n = 2;

    printf("Enter the lower limit: ");
    scanf("%f", &x0);

    printf("Enter the upper limit: ");
    scanf("%f", &xn);
    h = (xn - x0) / n;
    for (int i = 0; i <= n; i++)
    {
        if (i == 1)
        {
            res += 4 * f(x0 + i * h);
        }
        else
        {
            res += f(x0 + i * h);
        }
    }
    printf("Numerical integration for f(x): %.2f", res * h / 3);
    return 0;
}