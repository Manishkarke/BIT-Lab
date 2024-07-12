// Lab 06: C program to find the value f(x) using Newton's Divided difference Method
#include "stdio.h"
#include "math.h"
#define MAX_SIZE 20

void initialize(float[][MAX_SIZE], int);
// void displayTable(float[][MAX_SIZE], int);
void differenceTable(float[][MAX_SIZE], int);
void newtonDividedDifferenceMethod(float[][MAX_SIZE], float, int);

int main()
{
    float table[MAX_SIZE][MAX_SIZE], x;
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

    newtonDividedDifferenceMethod(table, x, n);

    return 0;
}

// Initialize the table
void initialize(float table[][MAX_SIZE], int n)
{
    for (int col = 0; col < n + 1; col++)
    {
        for (int row = 0; row < n; row++)
        {
            table[row][col] = 0;
        }
    }
}

// Display the table
// void displayTable(float table[][MAX_SIZE], int n)
// {
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < n + 1; col++)
//         {
//             printf("%.2f\t", table[row][col]);
//         }
//         printf("\n");
//     }
// }

// Calculate the difference table
void differenceTable(float table[][MAX_SIZE], int n)
{
    for (int col = 2; col < n + 1; col++)
    {
        for (int row = 0; row < n - (col - 1) && row >= 0; row++)
        {
            table[row][col] = (table[row + 1][col - 1] - table[row][col - 1]) /
                              (table[row + col - 1][0] - table[row][0]);
        }
    }
}

// Calculate the interpolation value
void newtonDividedDifferenceMethod(float table[][MAX_SIZE], float x, int n)
{
    float sum = table[0][1], mul;

    for (int i = 2; i < n + 1; i++)
    {
        mul = 1;

        for (int j = 0; j < i - 1; j++)
        {
            mul *= x - table[j][0];
        }

        sum += mul * table[0][i];
    }

    printf("The functional value for x = %.2f is %.2f", x, sum);
}