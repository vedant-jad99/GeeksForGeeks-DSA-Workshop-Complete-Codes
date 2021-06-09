/*
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.
Example:
        Input - n = 6, X = 13, arr[] = [1 4 45 6 10 8]
        Output - 1
        Explanation - The triplet {1, 4, 8} in the array sums up to 13.
        
        Input - n = 5, X = 10, arr[] = [1 2 4 3 6]
        Output - 1
        
Constraints:
        Time complexity - O(n^2)
        Space complexity - O(1)
        1 ≤ n ≤ 10^3
        1 ≤ A[i] ≤ 10^5
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
    public:
        bool find3Numbers(int A[], int n, int X)
        {
            sort(A, A + n);
            int index = 0;

            for(int i = n - 1; i >= 0; i--)
                if(A[i] < X) {
                    index = i;
                    break;
                }


            if(index == 0)
                return false;

            for(int i = index; i > 0; i--) {
                int l = 0, r = i - 1;
                while(l < r) {
                    if(A[l] + A[r] + A[i] == X)
                        return true;
                    else if(A[l] + A[r] + A[i] > X)
                        r--;
                    else
                        l++;
                }
            }
          Solution sol;
    cout<<sol.find3Numbers(A, n, X)<<"\n";
    return 0;
}
  return false;
        }

};

int main() {
    int n, X;
    cin>>n>>X;
    int A[n];
    
    for(int i = 0; i < n; i++)
        cin>>A[i];
        
    Solution sol;
    cout<<sol.find3Numbers(A, n, X)<<"\n";
    return 0;
}

    return 0;
}
