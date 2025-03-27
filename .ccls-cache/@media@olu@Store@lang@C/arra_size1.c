//
// Created by olu on 18/10/23.
//
// C Program to demonstrate usage of pointer arithmetic to
// find the size of arrays
#include <stdio.h>

void fun(int arr[], size_t arr_size)
{
    char const*const p2string = "some text";
    int i;
    for (i = 0; i < arr_size; i++) {
        arr[i] = i;
    }
}

// Driver Code
int main()
{
    int i;
    int arr[] = { 0, 0, 0, 0, 0 };
    size_t n = (&arr)[1] - arr;
    fun(arr, n);

    printf("The size of the array is: %ld", n);
    printf("\nThe elements are:\n");
    for (i = 0; i < n; i++)
        printf(" %d ", arr[i]);

    return 0;
}