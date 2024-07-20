#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int a[20];
    int size;
    int length;
} Array;

// Display operation on Array
void display(Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d \t", arr.a[i]);
    }
    printf("\n");
}

// Add operation on Array
void add(Array *arr, int data)
{
    if (arr->length != arr->size)
    {
        arr->a[arr->length] = data;
        arr->length++;
    }
    else
    {
        printf("Array is full");
    }
}

// Insert to an Index operation
void insert(Array *arr, int index, int data)
{
    int i, isConditionMatched = 0;
    if (index > arr->size && index <= 0)
    {
        printf("You cannot insert element exceeding its size. \n");
    }
    else if (arr->length == arr->size)
    {
        printf("The array is already full. \n");
    }
    else if (index == arr->length)
    {
        isConditionMatched = 1;
    }
    else
    {
        for (i = arr->length; i > index; i--)
        {
            arr->a[i] = arr->a[i - 1];
        }
        isConditionMatched = 1;
    }

    if (isConditionMatched == 1)
    {
        arr->a[index] = data;
        arr->length++;
    }
}

// Delete a element from an index from an array and return the deleted element
int delete(Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int deletedEl = arr->a[index];
        int i;
        for (i = index; i < arr->length; i++)
        {
            arr->a[i] = arr->a[i + 1];
        }
        arr->length--;
        return deletedEl;
    }
    else
    {
        printf("Invalid index: only index from 0 - %d is allowed.\n", arr->length - 1);
    }
}

// Function to change value of some index
void set(Array *arr, int index, int data)
{
    if (index >= 0 && index < arr->length)
    {
        arr->a[index] = data;
    }
    else
    {
        printf("Index is invalid.");
    }
}

// Function to get element of given index from an array
void get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.a[index];
    }
    else
    {
        printf("Invalid index. valid index are: 0 - %d \n", arr.length - 1);
    }
}

// function to get the maximum element of an array
int max(Array arr)
{
    int max = arr.a[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.a[i] > max)
        {
            max = arr.a[i];
        }
    }
    return max;
}

// function to get the minimum element of an array
int min(Array arr)
{
    int min = arr.a[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.a[i] < min)
        {
            min = arr.a[i];
        }
    }
    return min;
}

// Find the sum of all the element of an array
int sum(Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.a[i];
    }

    return total;
}

// sort an array


int main()
{
    Array a = {{10, 5, 3, 4, 5}, 20, 5};
    // display all the element of an array
    display(a);
    add(&a, 10);
    display(a);
    insert(&a, 2, 5);
    display(a);
    printf("Deleted el is %d and length is %d.\n", delete (&a, 3), a.length);
    display(a);
    printf("Deleted el is %d and length is %d.\n", delete (&a, 2), a.length);
    printf("Deleted el is %d and length is %d.\n", delete (&a, 1), a.length);
    display(a);
    return 0;
}