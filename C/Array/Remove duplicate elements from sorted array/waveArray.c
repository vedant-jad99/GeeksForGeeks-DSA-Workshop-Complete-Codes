/*Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it.
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
(considering the increasing lexicographical order).
Ex. Input - N = 5, Array = [1, 2, 3, 4, 5]
    Output - [2, 1, 4, 3, 5]
    Explanation - The above array forms a wave like pattern.

    Input - N = 8, Array = [2, 4, 7, 8, 9, 10]
    Output - [4, 2, 8, 7, 10, 9]

Constraints - 
    Time complexity - O(N)
    Space Complexity - O(1)

1 <= N <= 10^6
0 <= A[i] <= 10^7
*/

#include <stdio.h>
#define swap(T, x, y) do{T tmp = x; x = y; y = tmp;}while(0)

void convertToWave(int *a, int n) {
    for(int i = 0; i < n - 1; i += 2)
        swap(int, *(a + i), *(a + (i + 1)));
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    convertToWave(a, n);
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    
    return 0;
}