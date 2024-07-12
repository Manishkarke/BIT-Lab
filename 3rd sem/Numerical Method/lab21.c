// Lab 21: C program for For matrix factorization by using Do-little LU decomposition method
#include "stdio.h"

#define MAX 10

void printMatrix(float matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    float A[MAX][MAX], L[MAX][MAX], U[MAX][MAX];

    printf("Enter the size of matrix(max 9): ");
    scanf("%d", &n);

    printf("Enter the elements of %d * %d maxtrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);

            L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Perform Doolittle's LU Decomposition
    for (int i = 0; i < n; i++)
    {
        // Upper Triangular
        for (int k = i; k < n; k++)
        {
            float sum = 0;
            for (int j = 0; j < i; j++)
            {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++)
        {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else
            {
                float sum = 0;
                for (int j = 0; j < i; j++)
                {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    printf("\nLower Triangular Matrix L:\n");
    printMatrix(L, n);

    printf("\nUpper Triangular Matrix U:\n");
    printMatrix(U, n);

    return 0;
}