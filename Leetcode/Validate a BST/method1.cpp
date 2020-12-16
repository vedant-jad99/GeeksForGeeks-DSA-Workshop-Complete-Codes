/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:
        - The left subtree of a node contains only nodes with keys less than the node's key.
        - The right subtree of a node contains only nodes with keys greater than the node's key.
        - Both the left and right subtrees must also be binary search trees.

    Ex. Input - root = [5,1,4,null,null,3,6]
        Output - false
        Explanation - The BST is:
            5
           / \
          1   4
             / \
            3   6  

    Ex. Input - root = [2, 1, 3]
        Output - true
        Explanation - The BST is:
            2
           / \
          1   3

Constraints - 
    The number of nodes in the tree is in the range [1, 104].
    -2^31 <= Node.val <= 2^31 - 1
*/

//O(n) Time complexity
//O(n) Space complexity solution.

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val = 0;
    struct TreeNode *right = nullptr;
    struct TreeNode *left = nullptr;
}TreeNode;
void inorder(TreeNode *, vector<int> &);

TreeNode* newNode(int x) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = x;
    return node;
}
TreeNode* createTree() {
    TreeNode *root;
    int n;
    cin>>n;
    if(n == 0)
        return nullptr;
    root = newNode(n);
    root->left = createTree();
    root->right = createTree();
    return root;
}
void printTree(TreeNode *root) {
    if(root == nullptr)
        return;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}

bool isValidBST(TreeNode* root) {
    vector<int> v;
    
    inorder(root, v);
    for(unsigned int i = 1; i < v.size(); i++)
        if(v[i - 1] >= v[i])
            return false;
    return true;
}
void inorder(TreeNode *root, vector<int> &v) {
    if(root != nullptr) {
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
}

int main() {
    cout<<"Enter the node value of the tree. If null, enter 0."<<"\n\n";
    TreeNode* root = createTree();

    cout<<"The tree you entered: ";
    printTree(root);
    bool is_valid = isValidBST(root);

    if(is_valid)
        cout<<"\n\nThe tree is a valid BST."<<"\n";
    else
        cout<<"\n\nThe tree is not a valid BST."<<"\n";

    return 0;
}
