// Lab 12: C program to implement bubble sort
#include "stdio.h"
#define MAX 100

void bubbleSort(int [], int);

int main() {
    int nums[MAX], length;

    printf("Enter the numbers of number you want to sort(MAX %d): ", MAX);
    scanf("%d", &length);

    printf("Enter the numbers: ");
    for(int i = 0; i < length; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Orginal Array of numbers: ");
    for(int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    bubbleSort(nums, length);

    printf("Sorted Array of numbers: ");
    for(int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

// Function to sort the list
void bubbleSort(int nums[], int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - i - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
