/*Given an array arr[] of size N containing positive integers and an integer X, find the element in 
the array which is smaller than X and closest to it.
Ex. Input - N = 5 Array = {4 67 13 12 15} X = 16
    Output: 15
    Explanation: For a given value 16, there are four values which are smaller than it. But 15 is the 
    number which is smaller and closest to it with minimum difference of 1.

    Input - N = 5 Array = {1 2 3 4 5} X = 1
    Output: -1
    Explanation: No value is smaller than 1.

Constraints -
    Time complexity - O(N)
    Space complexity - O(1)

1 <= N <= 10^3
1 <= Arr[i], X <= 10^4
 */

#include <iostream>
#include <climits>

int immediateSmaller(int arr[], int n, int x)
{
    int min_diff = INT_MAX, diff, ans;
    
    for(int i = 0; i < n; i++) {
        diff = x - arr[i];
        if(diff > 0 && diff < min_diff) {
            min_diff = diff;
            ans = arr[i];
        }
    }
    
    if(min_diff == INT_MAX)
        return -1;
        
    return ans;
}

int main() {
    int n, x;
    std::cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++) 
        std::cin>>arr[i];
    std::cin>>x;
    
    int result = immediateSmaller(arr, n, x);
    std::cout<<result<<"\n";
}
