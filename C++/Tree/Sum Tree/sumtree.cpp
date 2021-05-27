/*
Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return 0.
An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
Example:
        Input - 3 2 N N 1
        Output - 1
        Explanation - Tree is SumTree
            3
           / \
          2   1
          
        Input - 10 20 10 N N 10 N N 30
        Output - 0
        Explanation - Not a SumTree
            10
           / \
          20  30
         / \
        10  10
        Note that if the root was 70, it would have been a SumTree
        
Constraints:
        Time complexity - O(N^2)
        Space complexity - O(1)
        1 ≤ number of nodes ≤ 10^4
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    private:
        int data;
    
    public:
        Node *left = NULL;
        Node *right = NULL;
        Node(int val) {
            data = val;
        }
        int getVal() {
            return data;
        }
};
Node *buildTree(vector<string> &v_str) {
    if(v_str.size() == 0)
        return NULL;
    
    string tmp = v_str.back();
    v_str.pop_back();
    if(tmp == "N")
        return NULL;
        
    Node *root = new Node(stoi(tmp));
    root->left = buildTree(v_str);
    root->right = buildTree(v_str);
    return root;
}
vector<string> NodeVals(string str) {
    string number = "";
    vector<string> v_str;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != ' ')
            number += str[i];
        else {
            v_str.push_back(number);
            number = "";
        }
    }
    v_str.push_back(number);
    
    reverse(v_str.begin(), v_str.end());
    return v_str;
}
void inorder(Node *root) {
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->getVal()<<" ";
    inorder(root->right);
}

//Solution
int sum(Node *root) {
    //Helper function
    if(root == NULL)
        return 0;
        
    return root->getVal() + sum(root->left) + sum(root->right);
}
bool isSumTree(Node* root) {
        if(root == NULL)
        return 1;
        
    if(root->left == NULL && root->right == NULL)
        return 1;
            
    int sum_left = sum(root->left);
    int sum_right = sum(root->right);
        
    if(sum_left + sum_right == root->getVal())
        return 1 && isSumTree(root->left) && isSumTree(root->right);
    else
        return 0;
}
//Ends here

int main() {
    string input;
    getline(cin, input);
    
    vector<string> nodes = NodeVals(input);
    Node *root = buildTree(nodes);
    inorder(root);
    cout<<"\n\n";
    
    cout<<isSumTree(root);
    return 0;
}
