/*
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another leaf node.
NOTE: Here Leaf node is a node which is connected to exactly one different node.
Example:
        Input -      
                   3                               
                 /    \                          
               4       5                     
              /  \      
            -10   4                          
        Output - 16
        Explanation - Maximum Sum lies between leaf node 4 and 5 = 4 + 4 + 3 + 5 = 16.
        
        Input -    
                    -15                               
                 /      \                          
                5         6                      
              /  \       / \
            -8    1     3   9
           /  \              \
          2   -3              0
                             / \
                            4  -1
                               /
                             10  
        Output -  27
        Explanation - The maximum possible sum from one leaf node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

Constraints:
        Time complexity - O(n)
        Space complexity - O(h) [Stack for recursion]
        2  ≤  Number of nodes  ≤  10^4
        -10^3  ≤ Value of each node ≤ 10^3
*/

#include <iostream>
#include <climits>

using namespace std;

class Solution {
    public:
        int maxPathSum(Node* root)
        {
            // code here
            int ans = INT_MIN;
            int ret_val = pathSum(root, ans);
            if(ans == INT_MIN)
                return ret_val;
            return ans;
        }
        //Utility function for calculating path
        int pathSum(Node *root, int &global) {
            if(root == NULL)
                return 0;
            if(root->left == NULL && root->right == NULL)
                return root->data;

            int l_val, r_val;
            if(root->left == NULL)
                return root->data + pathSum(root->right, global);
            if(root->right == NULL)
                return root->data + pathSum(root->left, global);

            l_val = pathSum(root->left, global);
            r_val = pathSum(root->right, global);
            global = max(global, l_val + r_val + root->data);

            return max(l_val + root->data, r_val + root->data);
        }
};
