#include <stdio.h>

int *prod_arr(int arr[], int new_arr[], int n) {
    int prod = 1;

    for(int i = 0; i < n; i++)
        prod *= arr[i];

    for(int i = 0; i < n; i++)
        new_arr[i] = prod/arr[i];
    
    return new_arr;
}

//Without division
int *prod_arr2(int arr[], int new_arr[], int n) {
    int temp = 1;
    for(int i = 0; i < n; i++) {
        new_arr[i] = temp;
        temp =   temp * arr[i];
    }
    temp = 1;
    for(int i = n - 1; i > -1; i--) {
        new_arr[i] = new_arr[i] * temp;
        temp = temp * arr[i];
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int arr[n], new_arr[n];
    for(int i = 0; i < n; i++) 
        scanf("%d", arr + i);
    
    prod_arr2(arr, new_arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", new_arr[i]);
}