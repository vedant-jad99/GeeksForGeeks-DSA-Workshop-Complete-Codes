/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
Example:
        Input -  
            Linked List 1 = 4->1->common
            Linked List 2 = 5->6->1->common
            common = 8->4->5->NULL
        Output - 8
        Explanation -  

        4              5
        |              |
        1              6
         \             /
          8   -----  1 
           |
           4
           |
          5
          |
          NULL       

        
        Input:
            LinkList1 = 3->6->9->common
            LinkList2 = 10->common
            common = 15->30->NULL
        Output - 15
        
Constraints:
        Time Complexity - O(N+M)
        Space Complexity - O(1)
        1 ≤ N + M ≤ 2*105
        -1000 ≤ value ≤ 1000
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
Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1 == NULL || head2 == NULL)
        return -1;
    if(head1 == head2)
        return head1->data;
    
    int counter = 1;
    Node *temp = head1, *temp2 = head2;
    while(head1->next != NULL) {
        head1 = head1->next;
        counter++;
    }
    head1->next = temp;
    for(int i = 0; i < counter; i++)
        if(head2->next == NULL)
            return -1;
        else
            head2 = head2->next;
    
    while(head2 != temp2) {
        if(head2 == NULL)
            return -1;
        head2 = head2->next;
        temp2 = temp2->next;
    }
    return temp2->data;
}

int main() {
    int n1, n2, n3;
    cin>>n1>>n2>>n3;
        
    Node* head1 = inputList(n1);
    Node* head2 = inputList(n2);
    Node* common = inputList(n3);
        
    Node* temp = head1;
    while(temp!=NULL && temp->next != NULL)
        temp = temp->next;
    
    if(temp!=NULL) 
        temp->next = common;
    temp = head2;
    while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
    
    if(temp!=NULL)
        temp->next = common;
        
    cout << intersectPoint(head1, head2) << endl;
    return 0;
}
