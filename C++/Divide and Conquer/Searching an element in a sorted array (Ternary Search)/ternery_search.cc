/*
Given a sorted array of size N and an integer K. Check if K is present in the array or not using ternary search.
Ternary Search - It is a divide and conquer algorithm that can be used to find an element in an array. 
It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the 
given array into three parts and determine which has the key (searched element).
Example:
        Input: N = 5, K = 6, arr[] = {1,2,3,4,6}
        Output: 1
        Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing),output is 1.

        Input: N = 5, K = 2, arr[] = {1,3,4,5,6}
        Output: -1

Constraints:
        Time Complexity - O(logN base 3)
        Space Complexity - O(1)
        1 <= N <= 10^6
        1 <= K <= 10^6
        1 <= arr[i] <= 10^6
*/

#include <iostream>
#include <cmath>

using namespace std;

int search(int, int, int [], int);

int ternarySearch(int arr[], int N, int K) 
{     
    return search(0, N - 1, arr, K);
}
int search(int beg, int end, int arr[], int K) {
    int N = end - beg + 1;
    int cut_length = ceil((double)N/3) - 1;
    int first_partition = beg + cut_length, second_partition = beg + 2 * cut_length + 1;
    
    if(K == arr[first_partition])
        return 1;
    else if(K == arr[second_partition])
        return 1;
    
    if(beg == first_partition )
        return -1;
    if(beg == second_partition)
        return -1;
    
    if(K < arr[first_partition]) 
        return search(beg, first_partition, arr, K);
    else if(K < arr[second_partition])
        return search(first_partition + 1, second_partition, arr, K);
    else
        return search(second_partition + 1, end, arr, K);
}

int main() {
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<ternarySearch(arr, n, k)<<"\n";
}
