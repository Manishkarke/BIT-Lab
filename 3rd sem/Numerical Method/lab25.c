#include "stdio.h"
#include "math.h"

#define g(x, y) (2 * (x) * (x) * (y) * (y))

int main()
{
    int n, i, j, k;
    float sum, err, E[10], a[10][10], b[10], new_x[10], old_x[10], tl, tr, tu, tb, h;

    printf("Enter dimension of plate: ");
    scanf("%d", &n);

    printf("Enter dimension of grid: ");
    scanf("%f", &h);

    printf("Enter temperature of left right bottom up: ");
    printf("%f %f %f %f", &tl, &tr, &tb, &tu);

    for (i = 0; i <= n; i++)
    {
        a[i][i] = 4;
    }

    for (i = 0; i <= n; i++)
    {
        a[i][n - i] = 0;
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i != j && j != (n - i))
            {
                a[i][j] = 1;
            }
        }
    }

    k = 0;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            b[k++] = h * h * g(i, j);
        }
    }

    k = 0;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (i - 1 == 0)
            {
                b[k] = b[k] - tl;
            }
            if (i + 1 == n)
            {
                b[k] = b[k] - tr;
            }

            if (j - 1 == 0)
            {
                b[k] = b[k] - tb;
            }
            if (j + 1 == n)
            {
                b[k] = b[k] - tu;
            }
            k++;
        }
    }

    printf("Enter the accuracy limit: ");
    scanf("%f", &err);

    for(i = 0; i <= n; i++) {
        new_x[i] = 0;
    }

    while(1) {
        for(i = 0; i <= n; i++) {
            
        }
    }
}