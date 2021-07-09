/*
Given an NxM 2D matrix, rearrange such that 
    Each diagonal in the lower left triangle of the rectangular grid is sorted in ascending order. 
    Each diagonal in the upper right triangle of the rectangular grid is sorted in descending order. 
    The major diagonal in the grid starting from the top-left corner is not rearranged. 
Example:
        Input - N = 4, M = 5 
                matrix = {{3 6 3 8 2},
                          {4 1 9 5 9},
                          {5 7 2 4 8},
                          {8 3 1 7 6}}
        Output -    3 9 8 9 2
                    1 1 6 5 8
                    3 4 2 6 3
                    8 5 7 7 4

Constraints:
        Time complexity - O(mn*log(mn))
        Space complexity - O(max(m,n))
        1 <= N,M <= 104 , 1<=N*M<=105
        1 <= matrix[i] <= 103
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        // code here 
        for(int i = 1; i < m; i++) {
            vector<int> temp = { };
            for(int j = i, k = 0; j < m && k < n; j++, k++ )
                temp.push_back(matrix[k][j]);
            
            sort(temp.rbegin(), temp.rend());
            int count = 0;
            for(int j = i, k = 0; j < m && k < n; j++, k++ )            
                matrix[k][j] = temp[count++];
        }
        
        for(int i = 1; i < n; i++) {
            vector<int> temp = { };
            for(int j = i, k = 0; j < n && k < m; j++, k++ )
                temp.push_back(matrix[j][k]);
            
            sort(temp.begin(), temp.end());
            int count = 0;
            for(int j = i, k = 0; j < n && k < m; j++, k++ )            
                matrix[j][k] = temp[count++];
        }
        
    }
};
