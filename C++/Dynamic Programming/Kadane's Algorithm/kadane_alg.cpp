/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
Example: 
        Input - N = 5, arr[] = {1,2,3,-2,5}
        Output - 9
        Explanation - Maximum sum = 1 + 2 + 3 - 2 + 5 = 9  

        Input - N = 4, arr[] = {-1,-2,-3,-4}
        Output - -1
        
Constraints:
        Time Complexity - O(N)
        Space Complexity - O(1)
        1 ≤ N ≤ 10^6
        -10^7 ≤ A[i] <= 10^7
*/

#include <iostream>

using namespace std;

int maxSubarraySum(int arr[], int n){
    int max_sum = arr[0];
    int look_ahead = 0;
    for(int i = 0; i < n; i++) {
        look_ahead += arr[i];
        if(look_ahead > max_sum)
            max_sum = look_ahead;
        if(look_ahead < 0)
            look_ahead = 0;
    }
    return max_sum;
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<"\n"<<maxSubarraySum(a, n)<<endl;
    return 0;
}
