// Lab 18: C program to To solve ordinary differential equation using RK 4’s method.
#include <stdio.h>
#include <math.h>

#define f(x, y) ((x) + (y)) // x + y

int main()
{
    float x, y, xn, h, m1, m2, m3, m4;
    int i, n;

    printf("Enter Initial values:\n");
    printf("x: ");
    scanf("%f", &x);
    printf("y: ");
    scanf("%f", &y);
    printf("Enter calculation point xn: ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    h = (xn - x) / n;

    for (i = 1; i <= n; i++)
    {
        m1 = f(x, y);
        m2 = f(x + h / 2, y + (m1 * h / 2));
        m3 = f(x + h / 2, y + (m2 * h / 2));
        m4 = f(x + h, y + (m3 * h));
        x = x + h;
        y = y + ((m1 + 2 * m2 + 2 * m3 + m4) * h) / 6;
    }

    /* Displaying result */
    printf("\nValue of y at x = %.2f is %.3f\n", x, y);

    return 0;
}
