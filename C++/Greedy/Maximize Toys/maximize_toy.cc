/*
Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you. Your task is to find maximum number of toys you can buy with K amount. 
Example:
        Input - N = 7, K = 50, arr[] = {1, 12, 5, 111, 200, 1000, 10}
        Output - 4
        Explaination - The costs of the toys you can buy are 1, 12, 5 and 10.

        Input - N = 3, K = 100, arr[] = {20, 30, 50}
        Output - 3

Constraints:
        Time complexity - O(n*logn)
        Space complexity - O(1)
        1 ≤ N ≤ 10^5
        1 ≤ K, arr[i] ≤ 10^9
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
      int toyCount(int N, int K, vector<int> arr)
      {
          // code here
          sort(arr.begin(), arr.end());
          int count = 0;

          for(int i = 0; i < N; i++) {
              K -= arr[i];
              if(K < 0)
                  break;
              count += 1;
          }

          return count;
      }
};

int main() {
    int N, K, temp;
    vector<int> v;
  
    cin>>N>>K;
    for(int i = 0; i < N; i++) {
        cin>>temp;
        v.push_back(temp);
    }
      
    cout<<toyCount(N, K, v)<<"\n";
    return 0;
}
