/*
Link to the question - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

Worst case - O(n^2)
Average case - O(kn), k = number of ones in first row
*/

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int ones;
        stack<int> s;
        
        for(int i = 1; i < n; i++) {
            if(M[0][i]) {
                ones = 1;
                
                for(int j = 1; j <  n; j++)
                    if(i != j && M[j][i])
                        ones += 1;
                
                if(ones == n - 1)
                    s.push(i);
            }
            
        }
        if(s.empty()) {
            ones = 0;
            for(int i = 1; i < n; i++)
                if(M[i][0])
                    ones++;
            
            if(ones == n - 1)
                return 0;
            return -1;
        }
        
        while(!s.empty()) {
            int index = s.top();
            s.pop();
            bool flag = false;
            
            for(int i = 0; i < n; i++)
                if(M[index][i] == 1) {
                    flag = ~flag;
                    break;
                }
            
            if(flag)
                continue;
            return index;
        }
        
        return -1;
    }
};
