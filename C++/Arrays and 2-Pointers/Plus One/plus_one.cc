/*
Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). The digits are stored such that the most 
significant digit is first element of array.
Example:
        Input - N = 3, arr[] = {1, 2, 4}
        Output - 1 2 5
        Explanation - 124+1 = 125, and so the Output
        
        Input - N = 3. arr[] = {9, 9, 9}
        Output - 1 0 0 0

Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        1 <= N <= 105
        0 <= arri <= 9
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        int carry = 0;
        
        reverse(arr.begin(), arr.end());
        for(int i = 0; i < N; i++) {
            if(i == 0) {
                carry = (arr[i] + 1)/10;
                arr[i] = (arr[i] + 1)%10;
                continue;
            }
            
            int temp = (arr[i] + carry)/10;
            arr[i] = (arr[i] + carry)%10;
            carry = temp;
        }
        if(carry > 0) 
            arr.push_back(carry);
        
        reverse(arr.begin(), arr.end());
        return arr;
    }
};

