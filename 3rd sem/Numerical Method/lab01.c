// Lab 01: To find the root of non-linear equation using bisection methods
#include "stdio.h"
#include "math.h"
#define f(x) ((x * x * x) - (4 * x) - 9)

void bisectionMethod(float *a, float *b, float err)
{
    float mid = 0, oldmid, e = 1;

    while ((err < e))
    {
        oldmid = mid;
        mid = (*a + *b) / 2;

        if (f(mid) < 0)
        {
            *a = mid;
        }
        else if (f(mid) == 0)
        {
            break;
        }
        else
        {
            *b = mid;
        }

        e = fabs((oldmid - mid) / mid);
    }

    printf("the root of the fuction is %.5f", mid);
}

int main()
{
    char choice;
    float a, b, errorExpected;

    do
    {
        printf("Enter the first and second guess values: ");
        scanf("%f %f", &a, &b);

        if (f(a) * f(b) < 0)
        {
            printf("Enter the stopping criteria between 0 and 1: ");
            scanf("%f", &errorExpected);

            bisectionMethod(&a, &b, errorExpected);
        } else
        {
            printf("The guess values are not right.\n");
        }

        printf("\n\nDo you want to continue?(y or n)\n");
        scanf("%c", &choice);
    } while (choice == 'y');

    return 0;
}