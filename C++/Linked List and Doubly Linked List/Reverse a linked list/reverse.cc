/*
Given a linked list of N nodes. The task is to reverse this list.
Example:
        Input - LinkedList: 1->2->3->4->5->6
        Output - 6 5 4 3 2 1
        Explanation - After reversing the list, elements are 6->5->4->3->2->1.
        
        Input - LinkedList: 2->7->8->9->10
        Output - 10 9 8 7 2
        Explanation - After reversing the list, elements are 10->9->8->7->2.
        
Constraints:
        Time complexity - O(N)
        Space complexity - O(1)
        1 <= N <= 10^4
*/

#include <iostream>

using namespace std;

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
            
        //Comment the next few lines if don't want recursive approach.
        struct Node *temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
      
        /*Uncomment for iterative approach
        struct Node *p = head->next, *q = head->next;
        head->next = NULL;
        while(q != NULL) {
            q = q->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
        */
    }
};
