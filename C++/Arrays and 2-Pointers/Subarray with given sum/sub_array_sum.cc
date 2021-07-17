/*
Link to the question - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int A[], int N, int K)
    {
        // Your code here
        int l = 0, r = 0, sum = 0;
        vector<int> ans = {-1, -1};
        
        while(r < N) {
            sum += A[r];
            if(sum > K) {
                while(sum > K) {
                    sum -= A[l];
                    l++;
                }
            }
            if(sum == K) {
                ans[0] = l + 1, ans[1] = r + 1;
                break;
            }
            r++;
        }
        
        if(ans[0] < 0 && ans[1] < 0)
            return vector<int> {-1};
        return ans;
    }
};
