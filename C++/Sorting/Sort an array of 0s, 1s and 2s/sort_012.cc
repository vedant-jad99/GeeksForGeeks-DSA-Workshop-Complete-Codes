//Link to the problem - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

#include <iostream>

using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int index_0 = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                a[i] = a[index_0];
                a[index_0] = 0;
                index_0++;
            }
        }
        int index_1 = index_0;
        for(int i = index_0; i < n; i++) {
            if(a[i] == 1) {
                a[i] = a[index_1];
                a[index_1] = 1;
                index_1++;
            }
        }
    }
    
};
