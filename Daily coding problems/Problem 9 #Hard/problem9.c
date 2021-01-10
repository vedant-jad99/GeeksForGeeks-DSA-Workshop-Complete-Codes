/*
Reference for this solution - https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
                            - https://medium.com/@divyabiyani26/daily-coding-problem-february-24th-2020-given-a-list-of-integers-write-a-function-that-89b68076b0fb
                            - https://www.techiedelight.com/maximum-sum-of-subsequence-with-no-adjacent-elements/

This is a very interesting DP problem. Similar to knapsack problem, just with adjacent constraint. 
*/

#include <stdio.h>
#include <math.h>

int findLargestSum(int arr[], int n) {
    int sum_incl = 0, sum_excl = 0, total_sum = 0;
    for(int i = 0; i < n; i++) {
        total_sum = (int)fmax(arr[i] + sum_incl, sum_excl);
        sum_incl = sum_excl;
        sum_excl = total_sum;
    }
    return total_sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    printf("\n%d\n", findLargestSum(arr, n));
    return 0;
}
