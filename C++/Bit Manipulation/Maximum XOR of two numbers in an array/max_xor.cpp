/*
Given an array of non-negative integers of size N. Find the maximum possible XOR between two numbers present in 
the array.
Example:
        Input - Arr = {25, 10, 2, 8, 5, 3}
        Output - 28
        Explanation - The maximum result is 5 ^ 25 = 28.

        Input - Arr = {1, 2, 3, 4, 5, 6, 7}
        Output - 7
        Explanation - The maximum result is 1 ^ 6 = 7.

Constraints:
        Time complexity - O(nlogn)
        Space complexity - O(n)
        1 <= N <=2*10^4
        1<= A[i] <= 10^6
*/

#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int max_xor(int arr[], int n) {
    //max_num stores the max ex-or
    //mask is for storing prefixes
    int max_num = 0, mask = 0, temp_max = arr[0];
        
    //finding the max number to know the MSB
    for(int i = 1; i < n; i++)
        if(arr[i] > temp_max)
            temp_max = arr[i];
            
    int digits = log2(temp_max);
    
    //traversing for total number of binary digits
    for(int i = digits; i > -1; i--) {
        unordered_set <int> s;

        //setting mask for prefixes like 10000, 11000, 11100, etc.
        mask |= (1 << i);

        //After ANDing with mask, we will get the numbers with respective MSBs ex.
        //11000 & 11001 will give 11000 and with 01010 will give 01000
        for(int j = 0; j < n; j++)
            s.insert(arr[j] & mask);
    
        //Setting candidate for max
        int candidate = max_num | 1 << i;
        
        for(auto i : s) {
            //If candidate 11000 and we ex-or it with 00010 (set element) we get 11010 which if present in set
            //means that it is present in array. It will be max then
            if(s.find(i ^ candidate) != s.end()) {
                max_num = candidate;
                break;
            }
        }
    }
    
    return max_num;
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<max_xor(a, n)<<"\n";
}
