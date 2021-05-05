/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is 
visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as 
argument. 
Example:
        Input - 1 2 3 4 5 6 7 N 8
        Ouput - 1 2 4 5 
        Left view of following tree is 1 2 4 8.
            1
            /\
           2  3
          /\  /\
         4 5 6 7
          \
           8

        Input - 1 3 2
        Output - 1 3

Constraints:
        Time Complexity - O(N)
        Space Complexity - O(H) H = height of tree
        0 <= Number of nodes <= 100
        1 <= Data of a node <= 1000
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

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
 */

int level_reached = 0;
void Iter(Node *, vector<int> &, int);
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   level_reached = 0;
   vector<int> vec;
   Iter(root, vec, 1);
   return vec;
}
void Iter(Node *root, vector<int> &vec, int max_level) {
    if(root != NULL) {
        if(max_level > level_reached) {
            vec.push_back(root->data);
            level_reached = max(max_level, level_reached);
        }
        Iter(root->left, vec, max_level + 1);
        Iter(root->right, vec, max_level + 1);
    }
    return;
}