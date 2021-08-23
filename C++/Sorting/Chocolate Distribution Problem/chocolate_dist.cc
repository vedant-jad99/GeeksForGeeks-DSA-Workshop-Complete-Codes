//Link to the problem - https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

#include <iostream>
#incldue <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long diff = INT_MAX;
        for(long long i = m; i <= n; i++) {
            diff = min((a[i - 1] - a[i - m]), diff);
        }
        return diff;
    }   
};
