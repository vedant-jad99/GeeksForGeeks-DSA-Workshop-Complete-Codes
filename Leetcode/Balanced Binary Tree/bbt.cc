/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
Example:
        Input - root = [3,9,20,null,null,15,7]
        Output - true
        
Constraints:
        Time complexity - O(n)
        Space complexity - O(h)
        The number of nodes in the tree is in the range [0, 5000].
        -104 <= Node.val <= 104
*/

#include <iostream>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        bool balanced = true;
        balancedTree(root, 0, balanced);
        return balanced;
    }
    int balancedTree(TreeNode *root, int height, bool &balanced) {
        if(root == NULL)
            return 0;
        
        int l = balancedTree(root->left, height + 1, balanced);
        int r = balancedTree(root->right, height + 1, balanced);
        
        if(abs(l - r) >= 2) {
            balanced = false;
        }
        return max(l, r) + 1;
    }
};
