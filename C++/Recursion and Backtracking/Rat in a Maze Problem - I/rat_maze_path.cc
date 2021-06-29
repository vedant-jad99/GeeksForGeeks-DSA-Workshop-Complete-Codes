/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from 
source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and 
rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. In case of no path, return an empty list. The driver will output "-1" automatically.
Example:
        Input - N = 4
                m[][] = {{1, 0, 0, 0},
                         {1, 1, 0, 1}, 
                         {1, 1, 0, 0},
                         {0, 1, 1, 1}}
        Output - DDRDRR DRDDRR
        Explanation - The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
        
        Input - N = 2
                m[][] = {{1, 0},
                         {1, 0}}
        Output - -1

Constraints:
        Time complexity - O((N^2)^4)
        Space complexity - O(L * X), L = length of the path, X = number of paths.
        2 ≤ N ≤ 5
        0 ≤ m[i][j] ≤ 1
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    vector<string> paths;
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        explore(m, n, "", 0, 0);
        return paths;
    }
    void explore(vector<vector<int>> &m, int n, string s, int i, int j) {
        if(i == n - 1 && j == n - 1 && m[i][j]) {
            paths.push_back(s);
            return;
        }
        
        if(isSafeIndex(n, i, j)) {
            if(m[i][j]) {
                m[i][j] = 0;
                explore(m, n, s + "D", i + 1, j); explore(m, n, s + "L", i, j - 1);
                explore(m, n, s + "R", i, j + 1); explore(m, n, s + "U", i - 1, j);
                m[i][j] = 1;
                return;
            }
            return;
        }
        return;
    }
    bool isSafeIndex(int n, int i, int j) {
        if(i == -1 || j == -1 || i == n || j == n)
            return false;
        return true;
    }
};
