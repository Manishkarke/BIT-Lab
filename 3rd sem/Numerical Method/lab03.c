// Lab 03: C program to find the root of a non linear equation using false point method
#include "stdio.h"
#include "math.h"

#define f(x) ((x * x * x) - (4 * x) - 9)

void falsePointMethod(float, float, float);

int main()
{
    float a, b, err;
    char choice;

    do
    {
        choice = 'n';
        printf("Enter the values:\n");

        printf("a: ");
        scanf("%f", &a);

        printf("b: ");
        scanf("%f", &b);

        printf("stopping criteria(0-1): ");
        scanf("%f", &err);

        if (f(a) * f(b) < 0)
        {
            falsePointMethod(a, b, err);
        }
        else
        {
            printf("Invalid guess value.\nDo you want to change guess value?(y or n)\n");
            scanf(" %c", &choice);
        }
    } while (choice == 'y');

    return 0;
}

void falsePointMethod(float a, float b, float err)
{
    float c, e = 1;

    while (e > err)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        e = fabs((c - b) / c);

        a = b;
        b = c;
    }

    printf("Root of the function: %.4f", c);
}