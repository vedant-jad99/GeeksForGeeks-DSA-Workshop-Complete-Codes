/*Given a sorted array of N numbers, we need to maximize the sum of selected numbers. At each step, you need 
to select a number A[i], delete one occurrence of A[i]-1 (if exists), and A[i] each from the array. Repeat these 
steps until the array gets empty. The problem is to maximize the sum of the selected numbers.
Example:
        Input - N = 6, arr = {1, 2, 2, 2, 3, 4}
        Output - 10
        Explanation - We select 4, so 4 and 3 are deleted leaving us with {1,2,2,2}. Then we select 2, so 2 & 1 
        are deleted. We are left with{2,2}. We select 2 in next two steps, thus the sum is 4+2+2+2=10.

        Input - N = 3, arr = {1, 2, 3}
        Output - 4

Constraints:
        Time Complexity - O(N)
        Space Complexity - O(N)
        1 ≤ N ≤ 10^5
        1 ≤ A[i] ≤ 10^5
*/

#include <bits/stdc++.h>

using namespace std;

int maximizeSum(int a[], int n) 
{
    stack<int> s;
    int sum = 0;
    
    for(int i = n - 1; i > -1; i--) {
        if(s.empty() || s.top() != a[i]) {
            sum += a[i];
            s.push(a[i] - 1);
        }
        else {
            s.pop();
            continue;
        }
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<"\n"<<maximizeSum(a, n)<<"\n";
}