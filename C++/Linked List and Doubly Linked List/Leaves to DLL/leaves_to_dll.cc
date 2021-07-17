#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *convertUtil(Node *, Node* &head);

Node * convertToDLL(Node *root){
    // add code here.
    if(root == NULL)
        return NULL;
    
    Node *head = NULL;
    convertUtil(root, head);
    
    return head;
}
Node *convertUtil(Node *root, Node* &head) {
    if(root == NULL)
        return NULL;
    
    if(root->left == NULL && root->right == NULL) {
        if(head) {
            root->right = head;
            head->left = root;
            head = root;
        }
        else
            head = root;
        return NULL;
    }
    
    root->right = convertUtil(root->right, head);
    root->left = convertUtil(root->left, head);
    return root;
}   
