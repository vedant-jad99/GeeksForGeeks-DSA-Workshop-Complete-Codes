/*
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that 
form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
Example:
        Input -   1
                 /  \
                2    3
        Output - 3
        
        Input -  10
                /   \
              20    30
            /   \ 
           40   60
        Output - 4
        
Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        1 <= Number of nodes <= 10000
        1 <= Data of a node <= 1000
*/

#include <iostream>

using namespace std;

class Solution {
  public:
    int diameter(Node* root) {
        // Your code here
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    int helper(Node *root, int &maxDiameter) {
        if(root == NULL)
            return 0;
            
        int l_val = helper(root->left, maxDiameter);
        int r_val = helper(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, l_val + r_val + 1);
        
        return max(r_val, l_val) + 1;
    }
};
