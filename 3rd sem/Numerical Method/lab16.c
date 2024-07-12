#include <stdio.h>
#include <math.h>

#define f(x, y) ((x) + (y)) // x + y

int main()
{
    float x, y, xn, h, dy, slope;
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

    /* Euler's Method */
    for (i = 0; i < n; i++)
    {
        slope = f(x, y);
        dy = y + h * slope;
        y = dy;
        x = x + h;
    }

    /* Displaying result */
    printf("\nValue of y at x = %.2f is %.3f\n", xn, dy);

    return 0;
}
