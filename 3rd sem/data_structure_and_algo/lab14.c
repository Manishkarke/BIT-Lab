// Lab 14: C program to implement insertion sort algorithm
// 53 22 23 121 75 20 22 1 5 53
#include "stdio.h"
#define MAX 100

void insertionSort(int[], int);

int main()
{
    int arr[MAX], n;

    printf("Enter the number of numbers you want to sort(MAX %d): ", MAX);
    scanf("%d", &n);

    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original Array of numbers: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);

    printf("Sorted Array of numbers: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];

        int j = i - 1;
        while(arr[j] > temp && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; 
    }
}