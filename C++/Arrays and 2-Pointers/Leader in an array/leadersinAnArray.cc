/*Given an array A of positive integers the task is to find the leaders in the array. An element of 
array is leader if it is greater than or equal to all the elements to its right side. The rightmost 
element is always a leader. 
Ex. Input - N = 6 Array = {16,17,4,3,5,2}
    Output - [17, 5, 2]
    Explanation - The first leader is 17 as it is greater than all the elements to its right.  
    Similarly, the next leader is 5. The right most element is always a leader so it is also included.

    Input - N = 5 Array = {1,2,3,4,0}
    Output - [4, 0]

Constraints -
    Time Complexity - O(N)
    Space Complexity - O(N)

1 <= N <= 10^7
0 <= A[i] <= 10^7
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leaders(int arr[], int n){
    vector<int> array;
    array.push_back(arr[n - 1]);
    int max = arr[n - 1];
    
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] >= max)
        {
            array.push_back(arr[i]);
            max = arr[i];
        }
    }
    
    reverse(array.begin(), array.end());
    return array;
}

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++) 
        cin>>arr[i];

    vector<int> res = leaders(arr, n);
    for(unsigned int i = 0;i < res.size(); i++)
        cout<<res[i]<<"\t";
    cout<<"\n";
    return 0;
}
