/*
Given a sorted array with possibly duplicate elements. The task is to find indexes of first and last occurrences of an element X in the given array.
Note: If the element is not present in the array return {-1,-1} as pair.
Example:
        Input - N = 9, v[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}, X = 5
        Output - 2 5
        Explanation - Index of first occurrence of 5 is 2 and index of last occurrence of 5 is 5.

        Input - N = 9, v[] = {1, 3, 5, 5, 5, 5, 7, 123, 125}, X = 7
        Output - 6 6

Constraints:
        Time complexity - O(logN)
        Space complexity - O(1)
        1 ≤ N ≤ 10^5
        1 ≤ v[i], X ≤ 10^18
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair <long, long> p = {-1, -1};
        long l = 0, r = v.size() - 1;
        p.first = binarySearchFirst(l, r, v, x);
        p.second = binarySearchLast(l, r, v, x);
        return p;
    }
    long binarySearchLast(long l, long r, vector<long long> v, long long x) {
        if(l > r)
            return -1;
            
        long mid = (l + r)/2;
        if(v[mid] < x)
            return binarySearchLast(mid + 1, r, v, x);
        else if(v[mid] > x)
            return binarySearchLast(l, mid - 1, v, x);
        else {
            if(v[mid] == x && mid == r)
                return mid;
            if(v[mid] == x && v[mid + 1] != x)
                return mid;
            else
                return binarySearchLast(mid + 1, r, v, x);
        }
    }
    long binarySearchFirst(long l, long r, vector<long long> v, long long x) {
        if(l > r)
            return -1;
        
        long mid = (l + r)/2;
        if(v[mid] < x)
            return binarySearchFirst(mid + 1, r, v, x);
        else if(v[mid] > x)
            return binarySearchFirst(l, mid - 1, v, x);
        else {
            if(v[mid] == x && mid == l)
                return mid;
            if(v[mid] == x && v[mid - 1] != x)
                return mid;
            else
                return binarySearchFirst(l, mid - 1, v, x);
        }
    }
};
