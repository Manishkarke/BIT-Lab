// Lab 13: C program to implement selection sort
#include "stdio.h"
#define MAX 100

void selectionSort(int[], int);

int main()
{
    int nums[MAX], length;

    printf("Enter the number of numbers you want to sort(MAX %d): ", MAX);
    scanf("%d", &length);

    printf("Enter the numbers: ");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Original Array of numbers: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    selectionSort(nums, length);

    printf("Sorted Array of numbers: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}

// Function to sort numbers array using selection sort
void selectionSort(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int small = i;

        // Search for the smallest number
        for (int j = i + 1; j < n; j++)
        {
            if (nums[small] > nums[j])
            {
                small = j;
            }
        }

        // Swap the numbers
        int temp = nums[small];
        nums[small] = nums[i];
        nums[i] = temp;
    }
}