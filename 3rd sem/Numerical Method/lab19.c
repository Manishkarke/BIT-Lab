// C program For solving system of equations using basic Gauss elimination method
#include <stdio.h>

#define MAX 10

int main()
{
    int i, j, k, n;
    float a[MAX][MAX], x[MAX], c, sumx;

    printf("Enter the number of unknowns(max 9): ");
    scanf("%d", &n);
    printf("Enter elements of %d * %d augmented matrix:\n", n, n + 1);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    /* Elimination process */
    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            c = a[i][k] / a[k][k];
            for (j = k; j < n + 1; j++)
            {
                a[i][j] -= c * a[k][j];
            }
        }
    }

    /* Display upper triangular matrix */
    printf("\nUpper triangular matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    /* Backward substitution */
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        sumx = 0;
        for (j = i + 1; j < n; j++)
        {
            sumx += x[j] * a[i][j];
        }
        x[i] = (a[i][n] - sumx) / a[i][i];
    }

    /* Display solution */
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]: %.3f\n", i + 1, x[i]);
    }

    return 0;
}
