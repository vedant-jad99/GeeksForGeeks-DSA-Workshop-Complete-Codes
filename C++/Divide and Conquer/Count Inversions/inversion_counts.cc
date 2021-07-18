/*
Link to the question - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
*/

#include <iostream>

using namespace std;

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long v[], long long p, long long mid, long long q) {
        long long A[mid - p + 1], B[q - mid];
        for(long long i = p, c = 0; i <= mid; i++, c++)
            A[c] = v[i];
        for(long long i = mid + 1, c = 0; i <= q; i++, c++)
            B[c] = v[i];
            
        long long inversions = 0;
        long long c = p, i = p, j = mid + 1;
    
        while(i <= mid && j <= q) {
            if(A[i - p] <= B[j - mid - 1]) {
                v[c++] = A[i - p];
                i++;
            }
            else {
                v[c++] = B[j - mid - 1];
                j++;
                inversions += mid - i + 1;
            }
        }
    
        int first = 0;
        while(i <= mid) {
            v[c++] = A[i - p];
            i++;
        }
        while(j <= q) {
            v[c++] = B[j - mid - 1];
            j++;
        }
    
        return inversions;
    }
    long long mergeSort(long long v[], long long p, long long q) {
        if(p == q)
            return 0;
    
        long mid = (p + q)/2;
        long a = mergeSort(v, p, mid);
        long b = mergeSort(v, mid + 1, q);
        
        return merge(v, p, mid, q) + a + b;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long start = 0, end = N - 1;
        return mergeSort(arr, start, end);
    }
};
