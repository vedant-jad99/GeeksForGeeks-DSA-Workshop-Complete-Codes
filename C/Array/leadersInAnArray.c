/*Given an array A of positive integers the task is to find the leaders in the array. An element of 
array is leader if it is greater than or equal to all the elements to its right side. The rightmost 
element is always a leader. 
Ex. Input - N = 6 Array = {16,17,4,3,5,2}
    Output - [17, 5, 2]
    Explanation - The first leader is 17 as it is greater than all the elements to its right.  
    Similarly, the next leader is 5. The right most element is always a leader so it is also included.

    Input - N = 5 Array = {1,2,3,4,0}
    Output - [4, 0]

Constraints -
    Time Complexity - O(N)
    Space Complexity - O(N)

1 <= N <= 10^7
0 <= A[i] <= 10^7
*/

#include <stdio.h>

int leaders(int a[], int *res, int n) {
    res[n - 1] = a[n - 1];
    int max = a[n - 1], count = 1;

    for(int i = n - 2; i >= 0; i--) {
        if(a[i] >= max) {
            max = a[i];
            res[n - count - 1] = a[i];
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n], res[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    int count = leaders(a, res, n);
    printf("\n\n");

    for(int i = 0; i < count; i++)
        printf("%d\n", res[n - (count - i)]);    
    return 0;
}