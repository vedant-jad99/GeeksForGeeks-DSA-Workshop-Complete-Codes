/*
Given an array A[] of N integers and an integer X. The task is to find the sum of three integers in A[] such that it is closest to 
X.
Example:
        Input - N = 4, A = [-1, 2, 1, 4], X = 1
        Output - 2
        Explanation - Triplet sum closest to 1 is 2 = -1 + 2 + 1

        Input - N = 5, A = [4, 2, 1, 5, 3], X = 5
        Output - 6
        
Constraints:
        Time complexity - O(N^2)
        Space complexity - O(1)
        3 ≤ N ≤ 10^3
        -10^3 ≤ Arr[i] ≤ 10^3
        -10^4 ≤ X ≤ 10^4
*/

#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int closest3Sum(int A[], int N, int X)
{
    // code here
    int minimum = INT_MAX, ans = 0;
    sort(A, A + N);
    for(int i = 0; i < N; i++) {
        int left = i + 1, right = N - 1;
        while(left < right) {
            int sum = A[i] + A[left] + A[right];
            if(minimum > abs(sum - X)) {
                minimum = abs(sum - X);
                ans = sum;
            }
            if(sum < X)
                left++;
            else
                right--;
        }
    }
    return ans;
}

int main()
{
    int N, X;
    cin>>N>>X;
    
    int A[N];
    for(int i = 0; i < N; i++)
        cin>>A[i];
        
    cout<<closest3Sum(A, N, X)<<"\n";
    return 0;
}
