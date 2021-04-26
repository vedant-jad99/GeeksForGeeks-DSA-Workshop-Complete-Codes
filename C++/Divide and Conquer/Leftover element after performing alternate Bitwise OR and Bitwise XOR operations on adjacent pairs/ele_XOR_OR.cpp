/*
Given an array A of N integers and a 2D matrix denoting q queries. Each query consists of two elements, index 
and value. Update value at index in A for each query and then perform the following operations to get the result 
for that query.
1. Perform bitwise OR on each pair 
2. Perform bitwise XOR on each pair 
Do this alternately till you are left with only a single element in A
Example:
        Input - N = 4
                A = {1, 4, 5, 6}
                q = 2
                query = {{0, 2}, {3, 5}}
        Output - 1 3
        Explanation - 1st query: 
                        Update the value of A[0] to 2 as given in the query pair.The array becomes {2, 4, 5, 6}.
                        1st iteration: Perform bitwise OR on pairs {2,4} and {5,6}. The array becomes {6,7}.
                        2nd iteration: Perform bitwise XOR on pairs {6,7}. The array becomes {1}.

                      2nd query: 
                        Update the value of A[3] to 5 as given in the query pair.The array becomes {2, 4, 5, 5}.
                        1st iteration: Perform bitwise OR on pairs {2,4} and {5,5}. The array becomes {6,5}.
                        2nd iteration: 6^5=3. The array becomes {3}.

Constraints: 
        Time Complexity - O(q*log(N))
        Space Complexity - O(1)
        1 ≤ N ≤ 105
        1 ≤ A[i] ≤ 105
        1 ≤ q ≤ 104
*/

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int divide(int [], int , int , int );

vector<int> left(int N, int A[], int q, vector<pair<int, int>> query)
{
    vector<int> answers;
    int pos = ceil(log2(N));
    pos = pos%2 == 0 ? 1 : 0;
    
    for(int i = 0; i < q; i++) {
        if(query[i].first >= N) {
            answers.push_back(-1);
            continue;
        }
        A[query[i].first] = query[i].second;
        answers.push_back(divide(A, 0, N - 1, pos));
    }
    
    return answers;
}
int divide(int arr[], int p, int q, int flip) {
    if(p == q) 
        return arr[p];
    else if(p + 1 == q)
        return arr[p] | arr[q];
    else {
        int n = (p + q)/2;
        int a = divide(arr, p, n, flip + 1);
        int b = divide(arr, n + 1, q, flip + 1);
        
        if(flip & 1)
            return a ^ b;
        else
            return a | b;
    }
}

int main() {
    int N, q, x, y;
    cin>>N;

    int A[N];
    for(int i = 0; i < N; i++) 
        cin>>A[i];

    cin>>q;
    vector<pair<int, int>> query(q);
    for(int i = 0; i < q; i++) {
       cin>>x>>y;
       query[i] = {x, y}; 
    }

    vector<int> answers = left(N, A, q, query);
    for(int i = 0; i < answers.size(); i++)
        cout<<answers[i]<<" ";
    cout<<"\n";
}
