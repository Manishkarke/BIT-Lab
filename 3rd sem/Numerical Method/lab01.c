// Naive Gauss Elimination method
#include "stdio.h"
#define max_size 20

// Read the data
void readCoeff(int n, float[max_size][max_size]);
void readRhs(int, float[max_size]);

void display1D(int n, float[max_size]);
void display2D(int n, float[max_size][max_size]);

int main()
{
    int size;
    float coeff[max_size][max_size], rhs[max_size], ans[max_size];

    // Step 1: Read the size of matrix
    printf("Enter the size of matrix: ");
    scanf("%d", &size);

    // step 2: Read the coefficients
    readCoeff(size, coeff);

    // Step 3: Read the RHS values
    readRhs(size, rhs);

    return 0;
}

// step 2: Read the coefficients
void readCoeff(int n, float coeff[max_size][max_size])
{
    printf("Enter coeffiecients for:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("coeff[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &coeff[i][j]);
        }
    }
}

// step 3: read the RHS of the equations
void readRhs(int n, float rhs[max_size])
{
    printf("Enter RHS Values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("rhs[%d]: ", i + 1);
        scanf("%f", &rhs[i]);
    }
}

void display2D(int n, float arr[max_size][max_size])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f\t", arr[i][j]);
        }
        printf("\n");
    }
}

void display1D(int n, float arr[max_size])
{
    for (int j = 0; j < n; j++)
    {
        printf("%.2f\t", arr[j]);
    }
}