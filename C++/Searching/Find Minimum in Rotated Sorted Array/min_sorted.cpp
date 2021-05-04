/*
Given the sorted rotated array nums of unique elements, rotated between 1 and n times, return the minimum 
element of this array.
Example:
        Input - arr[] = [3,4,5,1,2]
        Output - 1
        Explanation - Minimum element is 1

        Input - arr[] = [4,5,6,7,0,1,2]
        Output - 0

Constraints:
        Time Complexity - O(logN)
        Space Comeplexity - O(1)
        n == nums.length
        1 <= n <= 5000
        -5000 <= nums[i] <= 5000
*/

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& arr) {
    int l = 0, m, r = arr.size() - 1, n = arr.size() - 1;
    
    if(n == 0)
        return arr[0];
    else if(n == 1)
        return min(arr[1], arr[0]);
    
    while(l <= r) {
        m = l + (r - l)/2;
        if(m > 0 && arr[m] < arr[m - 1])
            return arr[m];
        else if(m < n && arr[m] > arr[m + 1])
            return arr[m + 1];
        else if(arr[m] > arr[n])
            l = m + 1;
        else
            r = m - 1;
    }
    return arr[l];
}

int main() {
    vector<int> vec{4, 5, 6, 7, -1, 1, 2};
    cout<<findMin(vec);
    return 0;
}
