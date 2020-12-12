/*Given a sorted array A of size N, delete all the duplicates elements from A.
Ex. Input - N = 5, Array = [2, 2, 2, 2, 2]
    Output - 2 (Return size = 2)
    Explanation - After removing duplicates we get only one element in array, 2

    Input - N = 14, Array = [1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4]
    Ouput - 1 2 3 4 (Return size = 4)
    Explanation - Remove all duplicate elements in the array

Constraints - 
Time Complexity - O(N)
Space Complexity - O(1)

1 <= N <= 10^4
1 <= A[i] <= 10^6
*/

#include <stdio.h>

int remove_duplicate(int a[], int n) {
    
    int index = 1, j = 1;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[j])
            j++;
        else {
            a[index] = a[j];
            index++; j++;
        }
    }

    return index;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    int new_size = remove_duplicate(a, n);
    printf("\n\n");

    for(int i = 0; i < new_size; i++) {
        printf("%d\n", a[i]);
    }
}