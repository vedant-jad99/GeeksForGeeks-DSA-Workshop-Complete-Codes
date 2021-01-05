/*
This is not my solution.
Explanation of this problem's solution - 
    https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
    https://medium.com/swlh/smallest-missing-positive-integer-in-an-array-b6f197e78a16
*/

#include <stdio.h>
#include <stdlib.h>
 
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int segregate(int arr[], int size)
{
    int j = 0, i;
    for (i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
 
    return j;
}
int findMissingPositive(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }

    for (i = 0; i < size; i++)
        if (arr[i] > 0)
            return i + 1;
 
    return size + 1;
}
int findMissing(int arr[], int size)
{
    int shift = segregate(arr, size);
    return findMissingPositive(arr + shift, size - shift);
}

int main()
{
    int arr[] = { 0, 10, 2, -10, -20 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int missing = findMissing(arr, arr_size);
    printf("The smallest positive missing number is %d ", missing);
    getchar();
    return 0;
}
