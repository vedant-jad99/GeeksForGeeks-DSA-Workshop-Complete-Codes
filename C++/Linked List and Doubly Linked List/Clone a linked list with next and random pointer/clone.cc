/*
Link to the question - https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
*/

#include <iostream>

using namespace std;

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *temp = head;
        while(temp != nullptr) {
            Node *copy = new Node(temp->data);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        
        temp = head;
        while(temp != nullptr) {
            if(temp->arb)   
                temp->next->arb = temp->arb->next;
            else
                temp->next->arb = temp->arb;
                
            temp = temp->next->next;
        }
        
        temp = head;
        Node *head2 = head->next;
        head = head->next;
        
        while(temp != nullptr) {
            temp->next = temp->next->next;
            if(head2->next)
                head2->next = head2->next->next;
            
            temp = temp->next;
            head2 = head2->next;
        }
        
        return head;
    }

};
