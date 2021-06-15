/*
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level. 
Example:
        Input -
                1
              /   \
             3     2

        Output - 3 2 1
        Explanation - Traversing level 1: 3 2, Traversing level 0: 1
        
        Input -
               10
              /  \
             20   30
            / \ 
           40  60

        Output - 40 60 20 30 10

Constraints:
        Time complexity - O(n)
        Space complexity - O(n)
        1 ≤ N ≤ 10^4
*/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef struct node {
    int data;
    struct node *left = NULL;
    struct node *right = NULL;
}Node;

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;    
    return temp;
}
Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
            
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

//Function to return reverse level order traversal
vector<int> reverseLevelOrder(Node *root)
{
    stack<int> st;
    queue<Node *> q;
    vector<int> ans;
    
    q.push(root);
    while(!q.empty()) {
        int elements = q.size();
        for(int i = 0; i < elements; i++) {
            Node *temp = q.front();
            q.pop();
            if(temp->right != NULL)
                q.push(temp->right);
            if(temp->left != NULL)
                q.push(temp->left);
            st.push(temp->data);
        }
    }
    
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
