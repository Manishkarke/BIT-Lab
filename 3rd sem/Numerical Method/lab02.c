// Lab 02: To find root of nonlinear equation using Newton Raphson method
#include "stdio.h"
#include "math.h"
#define f(x) ((x * x * x) - (4 * x) - 9)
#define df(x) ((3 * x * x) - 4)

void newtonRaphsonMethod(float, float);

int main()
{
    char choice;
    float x0, err;

    do
    {
        printf("Enter the guess value: ");
        scanf("%f", &x0);

        printf("Enter the stopping criteria between 0 and 1: ");
        scanf("%f", &err);

        newtonRaphsonMethod(x0, err);

        printf("\n\nDo you want to continue?(y or n)\n");
        scanf(" %c", &choice);
    } while (choice == 'y');

    return 0;
}

void newtonRaphsonMethod(float x0, float err)
{
    float x1, e = 1;
    if (f(x0) != 0)
    {
        while (e > err)
        {
            x1 = x0 - (f(x0) / df(x0));

            e = fabs((x1 - x0) / x1);

            x0 = x1;
        }
    }

    printf("The root of the function is %.5f", x1);
}