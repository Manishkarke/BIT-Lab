// Lab 23: C program for solving system of linear equation using Gauss-Seidel method
#include <stdio.h>
#include <math.h>

#define MAX 10
#define N 100
#define E 0.0001

int main()
{
    int i, j, n, iter;
    float a[MAX][MAX], b[MAX], x[MAX], x_new[MAX], sum, max_err, err;

    printf("Enter the number of unknowns (max 9): ");
    scanf("%d", &n);
    printf("Enter the coefficients of the matrix A:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constants vector b:\n");
    for (i = 0; i < n; i++)
    {
        printf("b[%d]: ", i);
        scanf("%f", &b[i]);
        x[i] = 0.0; // Initial guess
    }

    /* Gauss-Seidel Iteration Process */
    iter = 0;
    do
    {
        max_err = 0.0;

        for (i = 0; i < n; i++)
        {
            sum = 0.0;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += a[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / a[i][i];
            err = fabs(x_new[i] - x[i]);
            if (err > max_err)
            {
                max_err = err;
            }
            x[i] = x_new[i]; // Update x[i] immediately
        }

        iter++;
    } while (max_err > E && iter < N);

    /* Display the solution */
    printf("\nSolution after %d iterations:\n", iter);
    for (i = 0; i < n; i++)
    {
        printf("x[%d]: %.3f\n", i + 1, x[i]);
    }

    return 0;
}
