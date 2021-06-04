/*
Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the 
elements of nums except nums[i].
If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.
Example:
        Input - n = 5, arr = {10, 3, 5, 6, 2}
        Output - [180, 600, 360, 300, 900]
        Explanation - For i=0, P[i] = 3*5*6*2 = 180.
                      For i=1, P[i] = 10*5*6*2 = 600.
                      For i=2, P[i] = 10*3*6*2 = 360.
                      For i=3, P[i] = 10*3*5*2 = 300.
                      For i=4, P[i] = 10*3*5*6 = 900.

        Input - n = 2, arr = {12, 0}
        Output - [0, 12]
        
Constraints:
        Time complexity - O(n)
        Space complexity - O(n)
        1 <= n <= 1000
        0 <= numsi <= 200
        Array may contain duplicates.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
            if(n == 1)
                return {1};
            
            long long int r_arr[n], l_arr[n];
            vector<long long int> products;
            r_arr[0] = nums[0], l_arr[n - 1] = nums[n - 1];
            
            for(int i = 1; i < n; i++) {
                r_arr[i] = nums[i] * r_arr[i - 1];
                l_arr[n - i - 1] = nums[n - i - 1] * l_arr[n - i];
            }
            
            for(int i = 0; i < n; i++) 
                if(i == 0) 
                    products.push_back(l_arr[i + 1]);
                else if(i == n - 1)
                    products.push_back(r_arr[i - 1]);
                else
                    products.push_back(r_arr[i - 1] * l_arr[i + 1]);
                    
            return products;
        }
};

int main()
 {

    int n;
    cin>>n;
    vector<long long int> arr(n), vec(n);
        
    for(int i = 0; i < n; i++)
        cin>>arr[i];
        
    Solution obj;
    vec = obj.productExceptSelf(arr, n);

    for(int i = 0; i < n; i++)
        cout<<vec[i]<<" ";
    
    cout<<endl;
	return 0;
} 
