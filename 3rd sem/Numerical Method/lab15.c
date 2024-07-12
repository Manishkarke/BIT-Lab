#include <stdio.h>
#include <math.h>

#define f(x) (1 / (1 + (x) * (x)))

int main()
{
    float result = 0.0, x0, xn, T[10][10], h, sum, mid;
    int rows, columns, k, m;

    printf("Enter the values:\n");
    printf("Lower limit: ");
    scanf("%f", &x0);

    printf("Upper limit: ");
    scanf("%f", &xn);

    printf("p & q of the required T(p, q): ");
    scanf("%d %d", &rows, &columns);

    h = xn - x0;

    T[0][0] = h / 2 * (f(x0) + f(xn));

    for(int i = 1; i <= rows; i++) {
        int segments = pow(2, i - 1);
        sum = 0;
        for(k = 1; k <= segments; k++) {
            mid = x0 + (2 * k - 1) * h / pow(2, i);
            sum += f(mid);
        }

        T[i][0] = T[i-1][0] / 2 + sum * h / pow(2, i);
    }

    for(int i = 1; i <= rows; i++) {
        for(int k = 1; k <= i && k <= columns; k++) {
            m = i - k;
            T[m + k][k] = (pow(4, k) * T[m + k][k - 1] - T[m + k - 1][k - 1]) / (pow(4, k) - 1);
        }
    }

    printf("Numerical integration for f(x): %.3f\n", T[rows][columns]);

    return 0;
}
