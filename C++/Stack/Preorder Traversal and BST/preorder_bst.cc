/*
Link to the question - https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1#
*/

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int> s;
        bool greater = false;
        
        s.push(arr[0]);
        for(int i = 1; i < N; i++) {
            if(arr[i] < s.top() && !greater)
                s.push(arr[i]);
            else if(arr[i] < s.top())
                return 0;
            else {
                int last = 0;
                while(!s.empty() && s.top() < arr[i]) {
                    last = s.top();
                    s.pop();
                }
                
                s.push(arr[i]);
                s.push(last);
                greater = true;
            }
        }
        
        return 1;
    }
};
