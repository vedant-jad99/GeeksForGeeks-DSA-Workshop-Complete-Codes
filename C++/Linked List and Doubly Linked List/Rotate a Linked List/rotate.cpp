/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.
Example:
        Input - N = 5, value[] = {2, 4, 7, 8, 9}, k = 3
        Output - 8 9 2 4 7
        Explanation -
        Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
        Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
        Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

        Input - N = 8, value[] = {1, 2, 3, 4, 5, 6, 7, 8}, k = 4
        Output: 5 6 7 8 1 2 3 4
        
Constraints:
        Time complexity - O(N)
        Space complexity - O(1)
        1 <= N <= 10^3
        1 <= k <= N
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* rotate(Node* head, int k)
{
    // Your code here
    /*
    Method 1 - O(n + k)
    
    Node *temp = head, *tmp = temp;
    while(head->next != NULL)
        head = head->next;
            
    while(k-- > 0) {
        head->next = new Node(temp->data);
        temp = temp->next;
        head = head->next;
        delete(tmp);
        tmp = temp;
    }
    return temp;
    */
    
    //Method 2 - O(n)
    Node *temp = head;
    while(--k > 0) 
        head = head->next;
    
    if(head == NULL)
        return temp;
        
    Node *tmp = head;
    while(head->next != NULL) 
        head = head->next;
            
    head->next = temp;
    head = tmp->next;
    tmp->next = NULL;
        
    return head;
        
}
void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        head = rotate(head,k);
        printList(head);
    }
    return 1;
}
