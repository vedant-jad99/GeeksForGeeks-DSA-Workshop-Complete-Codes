/*Given an array arr[] of size N and two elements x and y, use counter variables to find which element 
appears most in the array, x or y. If both elements have the same frequency, then return the smaller 
element.
Ex. Input - N = 11 Array = {1,1,2,2,3,3,4,4,4,4,5} x = 4, y = 5
    Output: 4
    Explanation: frequency of 4 is 4, frequency of 5 is 1

    Input - N = 8 Array = {1,2,3,4,5,6,7,8} x = 1, y = 7
    Output: 1
    Explanation: frequency of 1 is 1, frequency of 7 is 1. Since 1 < 7, return 1.

Constraints - 
    Time complexity - O(N)
    Space complexity - O(1)

1 <= N <= 103
0 <= Arr[i] , x , y <= 10^8
*/

#include <stdio.h>

int majorityWins(int arr[], int n, int x,int y)
{
    int counter_x = 0, counter_y = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] ^ x)
            if(arr[i] ^ y)
                continue;
            else 
                counter_y++;
        else 
            counter_x++;
    }
    if(counter_x > counter_y)
        return x;
    else if(counter_y == counter_x)
        return x < y ? x : y;
    else
        return y;
}

int main() {
    int n, x, y;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) 
        scanf("%d", arr + i);

    scanf("%d %d", &x, &y);

    printf("%d", majorityWins(arr, n, x, y));
}