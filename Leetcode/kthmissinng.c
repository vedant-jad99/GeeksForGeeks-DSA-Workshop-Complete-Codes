/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array.
Ex. Input: arr = [2,3,4,7,11], k = 5
    Output: 9
    Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

    Input: arr = [1,2,3,4], k = 2
    Output: 6
    Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

Constraints - 
    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000
    1 <= k <= 1000
    arr[i] < arr[j] for 1 <= i < j <= arr.length
*/

#include <stdio.h>

int findKthMissing(int arr[], int n, int k) {
    int positive = 1, i = 0;
    while(i < n) {
        if(positive == arr[i]) {
            positive++;
            i++;
        }
        else {
            k--;
            if(!k)
                break;
            positive++;
        }
    }
    if(k > 0)
        return positive + k - 1;
    return positive;
}
int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);
    scanf("%d", &k);

    printf("%d", findKthMissing(arr, n, k));
    return 0;
}