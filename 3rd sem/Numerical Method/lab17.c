// C program to To solve ordinary differential equation using Heun’s method.
#include <stdio.h>
#include <math.h>

#define f(x, y) ((x) + (y)) // x + y

int main()
{
    float x, y, xn, h, m1, m2;
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
        m2 = f(x + h, y + (m1 * h));
        x = x + h;
        y = y + (m1 + m2) * h / 2;
    }

    /* Displaying result */
    printf("\nValue of y at x = %.2f is %.3f\n", x, y);

    return 0;
}
