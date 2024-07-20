// Lab 16: C program to implemented linear search
#include "stdio.h"
#define MAX 100

int linearSearch(int[], int, int);

int main()
{
    int nums[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 23, 24, 32}, target, index;

    int length = sizeof(nums) / sizeof(nums[0]);

    printf("Enter the element you want to search for: ");
    scanf("%d", &target);

    index = linearSearch(nums, target, length);

    if (index == -1)
    {
        printf("%d is not in the list.", target);
    }
    else
    {
        printf("%d is in the index: %d of the list.", target, index);
    }

    return 0;
}

// Linear Search Function
int linearSearch(int nums[], int target, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (nums[i] == target)
            return i;
    }

    return -1;
}