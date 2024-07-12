// Lab 20: C program for solving system of linear equation using gauss jordan method
#include <stdio.h>

#define MAX 10

int main()
{
    int i, j, k, n;
    float a[MAX][MAX], x[MAX], c;

    printf("Enter the number of unknowns (max 9): ");
    scanf("%d", &n);
    printf("Enter elements of %d * %d augmented matrix:\n", n, n + 1);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    /* Gauss-Jordan Elimination Process */
    for (k = 0; k < n; k++)
    {
        // Make the diagonal element 1
        c = a[k][k];
        for (j = 0; j < n + 1; j++)
        {
            a[k][j] = a[k][j] / c;
        }

        // Make the other elements in the column 0
        for (i = 0; i < n; i++)
        {
            if (i != k)
            {
                c = a[i][k];
                for (j = 0; j < n + 1; j++)
                {
                    a[i][j] = a[i][j] - c * a[k][j];
                }
            }
        }
    }

    /* Display the matrix after Gauss-Jordan elimination */
    printf("\nMatrix after Gauss-Jordan elimination:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    /* Display the solution */
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]: %.3f\n", i + 1, a[i][n]);
    }

    return 0;
}
