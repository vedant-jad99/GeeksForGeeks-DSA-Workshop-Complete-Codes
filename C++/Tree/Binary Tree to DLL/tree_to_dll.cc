#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        return convertUtil(root, 1);
    }
    Node *convertUtil(Node *root, int ret_val) {
        if(root == nullptr)
            return root;
        if(root->left == nullptr && root->right == nullptr)
            return root;
            
        root->left = convertUtil(root->left, -1);
        root->right = convertUtil(root->right, 1);
        
        if(root->left)
            root->left->right = root;
        if(root->right)
            root->right->left = root;
        if(ret_val == -1) {
            while(root->right != nullptr)
                root = root->right;
        }
        else {
            while(root->left != nullptr)
                root = root->left;
        }
        
        return root;
    }
};
