/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect 
two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
Example:
        Input - n = 4, arr[] = {4, 3, 2, 6}
        Output - 29
        Explanation - For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in 
                      following ways.
                      1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
                      2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
                      3) Finally connect the two ropes and all ropes have connected.
                      Total cost for connecting all ropes is 5 + 9 + 15 = 29.

        Input - n = 5, arr[] = {4, 2, 7, 6, 9}
        Output - 62

Constraints:
        Time complexity - O(n*logn)
        Space complexity - O(n)
        1 ≤ N ≤ 100000
        1 ≤ arr[i] ≤ 10^6
*/

#include <iostream>
#include <queue>

using namespace std;

long long minCost(long long arr[], long long n) {
    priority_queue<long long> heap;
    long long cost = 0;
    
    for(long long i = 0; i < n; i++)
        heap.push(-arr[i]);
        
    while(heap.size() > 1) {
        long long a, b;
        a = heap.top(); heap.pop();
        b = heap.top(); heap.pop();
        
        cost += (a + b);
        heap.push(a + b);
    }
    
    return -cost;
}
int main() {
    long long n;
    cin>>n;

    long long a[n];
    for(long long i = 0; i < n; i++)
        cin>>a[i];

    cout<<minCost(a, n)<<endl;
}