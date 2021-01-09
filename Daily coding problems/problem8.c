#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define null NULL

typedef struct binary_tree {
    int val;
    struct binary_tree *left;
    struct binary_tree *right;
}Tree;

Tree *createNode(int val) {
    Tree *node = (Tree*)malloc(sizeof(Tree));
    node->val = val;
    node->left = null;
    node->right = null;
    return node;
}
Tree *tree() {
    int n;
    scanf("%d", &n);
    if(n == -1) 
        return null;
    Tree *root = createNode(n);
    root->left = tree();
    root->right = tree();
    return root;
}
void printTree(Tree *root) {
    if(root != null) {
        printf("%d ", root->val);
        printTree(root->left);
        printTree(root->right);
    }
}

bool unival_subtrees(Tree *root, int *s) {
    static int count = 0;
    if(root == null)
        return true;
    if(root->left == null && root->right == null) {
        count++;
        printf("\n- %d", count);
        return true;
    }

    bool left_val = unival_subtrees(root->left, s);
    bool right_val = unival_subtrees(root->right, s);
    if(left_val && right_val) {
        if((root->left == null && root->val == root->right->val) || (root->right == null && root->val == root->left->val) || (root->val == root->left->val && root->val == root->right->val)) {
            count++;
            *s = count;
            printf("\n- %d", count);
            return true;
        }
    }
    return false;
}

int main() {
    Tree *root;
    root = tree();
    printf("\n\n");
    printTree(root);

    int s = 0, *ptr = &s;
    unival_subtrees(root, ptr);
    printf("\n\n%d\n", s);
    return 0;
}