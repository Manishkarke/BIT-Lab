// Lab 11: C program to find the numerical integration of a function using simpson's 3/8 rule
#include "stdio.h"

#define f(x) (1 / (1 + x))

int main()
{
    float h, x0, xn, res = 0;
    int n = 3;

    printf("Enter the lower limit: ");
    scanf("%f", &x0);

    printf("Enter the upper limit: ");
    scanf("%f", &xn);
    h = (xn - x0) / n;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
        {
            res += f(x0 + i * h);
        }
        else
        {
            res += 3 * f(x0 + i * h);
        }
    }
    printf("Numerical integration for f(x): %.2f", res * h * 3 / 8);
    return 0;
}