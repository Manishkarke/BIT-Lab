// Lab 12: C program to find the numerical integration of a function using composite simpson's 1 / 3 rule
#include "stdio.h"

#define f(x) 1 / (1 + x * x)

int main()
{
    float  h, x0, xn, res = 0.0, k;
    int n;

    printf("Enter the lower limit: ");
    scanf("%f", &x0);

    printf("Enter the upper limit: ");
    scanf("%f", &xn);

    printf("Enter the number of segments: ");
    scanf("%d", &n);

    h = (xn - x0) / n;
    
    for(int i = 0; i <= n; i++) {
        k = x0 + i * h;
        if(i == 0 || i == n) {
            res += f(k);
        } else if(i % 2 == 0) {
            res += 2 * f(k);
        } else {
            res += 4 * f(k);
        }
    }

    res *= h/3;
    printf("Numerical integration for f(x): %.3f", res);

    return 0;
}