/*
Given an array A(1 indexed) of N friends, such that ith element is best friend of A[i]. The relation is uni-directional. Find all the pairs of best friends in the given array. A
best friends pair is if for i, j such that i != j and A[i] = j and A[j] = i.
Example:
        Input - A = [3,1,2]
        Output - 0
        Explanation - There is no best friend pair in the array
        
        Input - A = [2,1,1]
        Output - 1
        
Constraints:
        Time complexity - O(N)
        Space complexity - O(1)
        1 <= A[i] <= N
*/

#include <iostream>
#include <vector>

using namespace std;

int bestFriends(vector<int> A) {
    int N = A.size(), count = 0;
    
    for(int i = 0; i < N; i++) {
        if(A[i] == 0 || A[A[i] - 1] == 0)
            continue;
        else {
            if(A[A[i] - 1] == i + 1 && A[i] - 1 != i) {
                A[A[i] - 1] = 0;
                A[i] = 0;
                count++;
            }
        }
    }
    return count;
}
int main() {
    int N, T;
    cin>>T;
    while(T-- > 0) {
        cin>>N;
        vector<int> A(N, 0);
        
        for(int i = 0; i < N; i++)
            cin>>A[i];
        
        cout<<bestFriends(A)<<"\n";
    }
    return 0;
}
