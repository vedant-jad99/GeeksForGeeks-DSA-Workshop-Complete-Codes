/*
https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#
*/

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        // Complete the function
        
        unordered_map<int, int> m;
        unordered_map<int, int>::iterator it;
        int interval = 0;
        
        for(int i = 0; i < N; i++) {
            if(i != 0)
                arr[i] += arr[i - 1];
            
            if(arr[i] == K)
                interval = max(interval, i + 1);
            else {
                it = m.find(arr[i] - K);
                if(it != m.end())
                    interval = max(interval, i - it->second);
            }
            
            m.insert({arr[i], i});
        }
        
        return interval;
    } 

};
