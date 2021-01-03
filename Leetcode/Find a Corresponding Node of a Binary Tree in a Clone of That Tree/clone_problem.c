/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.
The cloned tree is a copy of the original tree. Return a reference to the same node in the cloned tree.
Note that you are not allowed to change any of the two trees or the target node and the answer must be 
a reference to a node in the cloned tree.

Follow up : Solve the problem if repeated values on the tree are allowed.
Ex. Screenshots of example are present in the folder.

Constraints - 
    The number of nodes in the tree is in the range [1, 10^4].
    The values of the nodes of the tree are unique.
    target node is a node from the original tree and is not null

Solution - 
    This is the solution for follow up. Works for og question too.
*/

//driver code
#include <stdio.h>
#include <stdlib.h>
#define null NULL

typedef struct tree {
    int val;
    struct tree *left;
    struct tree *right;
}TreeNode;

TreeNode *newNode(int x) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = x;
    node->left = null;
    node->right = null;
    return node;
}
TreeNode *createTree() {
    int n;
    TreeNode* root;
    scanf("%d", &n);
    if(n == 0)
        return null;
    root = newNode(n);
    root->left = createTree();
    root->right = createTree();
    return root;
}
TreeNode *clone(TreeNode *root) {
    TreeNode *clone_root;
    if(root == null)
        return null;
    clone_root = newNode(root->val);
    clone_root->left = clone(root->left);
    clone_root->right = clone(root->right);
    return clone_root;
}
TreeNode *getTarget(TreeNode *root, int n) {
    if(root == null)
        return null;
    static int s = 0;
    s++;
    if(n == s)
        return root;
    else {
        TreeNode *leftnode = getTarget(root->left, n);
        if(leftnode)
            return leftnode;
        return getTarget(root->right, n);
    }
}
void printTree(TreeNode *root) {
    if(root == null)
        return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

//Solution
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(original == null)
        return null;
    if(target == original)
        return cloned;
    
    TreeNode *leftnode = getTargetCopy(original->left, cloned->left, target);
    if(leftnode)
        return leftnode;
    TreeNode *rightnode = getTargetCopy(original->right, cloned->right, target);
    return rightnode;
}

//driver code
int main() {
    TreeNode *root = createTree();
    TreeNode *clone_root = clone(root);
    static int s = 0; int n;

    printTree(root);
    printf("\n\n");
    printTree(root);
    printf("\n\n");
    scanf("%d", &n);
    TreeNode *target = getTarget(root, n);
    printf("Target in original - %d\n\n", target->val);
    
    TreeNode *clone_target = getTargetCopy(root, clone_root, target);

    printf("Target in cloned - %d\n\n", clone_target->val);
    return 0;
}
