/*
Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.
Example:
        Input - n = 9, arr[] = {1,15,25,45,42,21,17,12,11}
        Output - 45
        Explanation - Maximum element is 45.
        
        Input - n = 5, arr[] = {1,42,47,50,5}
        Output - 50
        
Constraints:
        Time complexity - O(logn)
        Space complexity - O(1)
        3 ≤ n ≤ 10^6
        1 ≤ arr[i] ≤ 10^6
*/

#include <iostream>

using namespace std;

class Solution{
    public:
    	int findMaximum(int arr[], int n) {
    	    int l = 0, r = n - 1, m;
    	    while(l <= r) {
    	        m = (l + r)/2;
    	        if(m + 1 == n || (arr[m + 1] < arr[m] && arr[m] > arr[m - 1]))
    	            return arr[m];
    	        else
    	            if(arr[m + 1] < arr[m])
    	                r = m - 1;
    	            else
    	                l = m + 1;
    	    }
    	}
};

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    Solution ob;
    auto ans = ob.findMaximum(arr, n);
    cout<<ans<<"\n";
    
    return 0;
}
