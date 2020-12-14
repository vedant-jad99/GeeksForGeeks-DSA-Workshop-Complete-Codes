/*Given a sorted array containing only 0s and 1s, find the transition point.
Ex. Input - N = 5 Array = {0,0,0,1,1}
    Output - 3
    Explanation - Index 3 is the transition point where 1 begins.

    Input - N = 4 Array = {0, 0, 0, 0}
    Output - -1
    Explanation - No 1 in the array

Constraints - 
    Time complexity - O(logN)
    Space complexity - O(1)

1 ≤ N ≤ 500000
0 ≤ Arr[i] ≤ 1
*/

#include <stdio.h>

int findTransitionPoint(int arr[], int n) {
    if(arr[0] == 1)
        return 0;
    else if(arr[n - 1] == 0)
        return -1;
    else {
        int l = 0, r = n - 1, m;

        while(1) {
            m = (l + r)/2;
            
            if(arr[m] == 1)
                r = m;
            else {
                if(arr[m + 1] == 1)
                    return m + 1;
                l = m + 1;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) 
        scanf("%d", a + i);

    printf("%d\n", findTransitionPoint(a, n));
}