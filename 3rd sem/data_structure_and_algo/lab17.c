// Lab 17: C program to implement binary Search
#include "stdio.h"
#define MAX 100
int binarySearch(int[], int, int);

int main()
{
    int arr[MAX] = {1, 2, 4, 5, 8, 9, 10, 12, 23, 24, 32}, target, index;

    int length = sizeof(arr) / sizeof(arr[0]);
    length = 11;

    printf("Enter the element you want to search for: ");
    scanf("%d", &target);

    index = binarySearch(arr, target, length);

    if (index == -1)
    {
        printf("%d is not in the list.", target);
    }
    else
    {
        printf("%d is in the index %d of the list.", target, index);
    }

    return 0;
}

// Binary Search Function
int binarySearch(int arr[], int target, int n)
{
    int start = 0, end = n - 1, mid;

    {
        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }
}