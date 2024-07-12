// Lab 07: C program to calculate derivative using newton's forward difference
#include "stdio.h"
#include "math.h"

#define MAX 20

void differenceTable(float[][MAX], int);
void displayTable(float[][MAX], int);
void calculateDerivative(float[][MAX], int, float);
void initialize(float[][MAX], int);
int factorial(int);

int main()
{
    float table[MAX][MAX], x;
    int n;

    printf("Enter the number of data points(max: 19): ");
    scanf("%d", &n);

    initialize(table, n);

    // Get the values for x
    printf("Enter values for x:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%f", &table[i][0]);
    }

    // Get the values for f(x)
    printf("Enter values for f(x):\n");
    for (int i = 0; i < n; i++)
    {
        printf("f(x[%d]): ", i);
        scanf("%f", &table[i][1]);
    }

    printf("Enter the value of x for which you want to find f(x): ");
    scanf("%f", &x);

    differenceTable(table, n);

    displayTable(table, n);
    
    calculateDerivative(table, n, x);

    return 0;
}

// Initialize all table value to 0
void initialize(float table[][MAX], int n)
{
    for (int col = 0; col < n + 1; col++)
    {
        for (int row = 0; row < n; row++)
        {
            table[row][col] = 0;
        }
    }
}

// Difference Table Calculation
void differenceTable(float table[][MAX], int n)
{
    for (int col = 2; col <= n; col++)
    {
        for (int row = 0; row < n - (col - 1) && row >= 0; row++)
        {
            table[row][col] = (table[row + 1][col - 1] - table[row][col - 1]);
        }
    }
}

// Calculate factorial
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Calculate first derivative at x
void calculateDerivative(float table[][MAX], int n, float x)
{
    float sum = 0, h = table[1][0] - table[0][0];
    float s = (x - table[0][0]) / h;

    for (int i = 1; i < n; i++)
    {
        float term = table[0][i + 1] / factorial(i);
        for (int j = 1; j < i; j++)
        {
            term *= (s - j);
        }
        sum += term;
    }

    printf("The value of the first derivative f'(%.2f) is: %.2f\n", x, (sum / h));
}

void displayTable(float table[][MAX], int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n + 1; col++)
        {
            printf("%.2f\t", table[row][col]);
        }
        printf("\n");
    }
}