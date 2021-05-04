/*
Given a sorted array consisting 0’s and 1’s. The task is to find the index of first ‘1’ in the given array.
Example:
        Input - arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
        Output - 6
        Explanation - The index of first 1 in the array is 6.

        Input - arr[] = {0, 0, 0, 0}
        Output - -1
        Explanation - 1's are not present in the array.

Constraints:
        Time Complexity - O(logN)
        Space Comeplexity - O(1)
        1 ≤ N ≤ 10^6
        0 ≤ Ai ≤ 1
*/

#include <iostream>

using namespace std;

int firstIndex(int row[], int n) 
{
    // Your code goes here
    int l = 0, r = n - 1, m;

    while(l <= r) {
        m = l + (r - l)/2;
        if(row[m] == 1)
            if(m == 0 || row[m - 1] == 0)
                return m;
            else
                r = m - 1;
        else
            if(row[m + 1] == 1)
                return m + 1;
            else
                l = m + 1;  
    }
    return -1;
}
int main() {
    int a[] = {0, 0, 1, 1, 1, 1};
    cout<<firstIndex(a, 6)<<"\n";
    return 0;
}
