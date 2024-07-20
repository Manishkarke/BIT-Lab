#include "stdio.h"
#define MAX 100

int partition(int[], int, int);
void quickSort(int[], int, int);
void swap(int *, int *);

int main()
{
    int arr[MAX] = {19, 17, 15, 12, 16, 18, 4, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Adjust length for uninitialized elements
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            n = i;
            break;
        }
    }

    // Printing the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    // Printing the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);

        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

// Partitioning the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to swap array values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
