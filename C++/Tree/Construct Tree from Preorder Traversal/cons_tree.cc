#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* util(int n, int &i, int pre[], char preLN[]) {
    if(i >= n)
        return nullptr;
        
    struct Node* root;
    root = new Node(pre[i]);
    if(preLN[i] == 'N') {
        root->left = util(n, ++i, pre, preLN);
        root->right = util(n, ++i, pre, preLN);
    }
    return root;
} 
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index = 0;
    return util(n, index, pre, preLN);
}
