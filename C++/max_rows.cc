/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row 
that has the maximum number of 1's.
Example: 
        Input - N = 4 , M = 4, Arr[][] = {{0, 1, 1, 1},
                                        {0, 0, 1, 1},
                                        {1, 1, 1, 1},
                                        {0, 0, 0, 0}}
        Output - 2
        Explanation - Row 2 contains 4 1's (0-based indexing).

        Input - N = 2, M = 2, Arr[][] = {{0, 0}, {1, 1}}
        Output - 1
        Explanation - Row 1 contains 2 1's (0-based indexing).

Constraints:
        Time Complexity - O(n*Logm)
        Space Complexity - O(1)
        1 ≤ N, M ≤ 10^3
        0 ≤ Arr[i][j] ≤ 1 
*/

#include <iostream>
#include <vector>

using namespace std;

int findLeftMost1(vector<int> );

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    // code here
    int left = findLeftMost1(arr[0]), max = 0, index = 0;
    if(left >= 0)
        max = m - left;

    for(int i = 1; i < n; i++) {
        if(left == -1 || arr[i][left] == 1) {
            left = findLeftMost1(arr[i]);
            if(left != -1 && max < m - left) {
                max = m - left;
                index = i;
            }
            else if(left == -1)
                index = -1;
        }
    } 
    return index;
}
int findLeftMost1(vector<int> row) {
    int l = 0, r = row.size() - 1, n = r, m;

    while(l <= r) {
        m = l + (r - l)/2;
        if(row[m] == 1)
            if(m == 0 || row[m - 1] == 0)
                return m;
            else
                r = m - 1;
        else
            if(row[m + 1] == 1)
                return m + 1;
            else
                l = m + 1;  
    }
    return -1;
}

int main() {
    vector<vector<int>> vec{{0, 0}, {1, 1}};
    cout<<rowWithMax1s(vec, 2, 2)<<"\n";
    return 0;
}