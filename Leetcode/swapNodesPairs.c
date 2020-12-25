/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes. Only nodes itself may be changed.
Ex. Input - [1, 2, 3, 4]
    Output - 2->1->4->3
    Explanation - 1 is swapped with 2, 3 is swapped with 4

    Input - [1, 2, 3]
    Output - 2->1->3

Constriants - 

Time Complexity - O(n)
Space Complexity - O(1)

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/

//Driver code
#include <stdio.h>
#include <stdlib.h>
#define nullptr NULL

typedef struct linkedlist {
    int val;
    struct linkedlist *next;
}ListNode;

ListNode *createNode(int x) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->val = x;
    node->next = nullptr;
    return node;
}
ListNode *createLinkedList(int n) {
    int tmp_val;
    ListNode *head = nullptr, *p;

    for(int i = 0; i < n; i++) {
        p = head;
        scanf("%d", &tmp_val);
        if(p) {
            while(p->next != nullptr)
                p = p->next;
            p->next = createNode(tmp_val);
        }
        else 
            head = createNode(tmp_val);
    }
    return head;
}
void printNodes(ListNode *head) {
    while(head != nullptr) {
        if(head->next != nullptr)
            printf("%d->", head->val);
        else
            printf("%d", head->val);
        head = head->next;
    }
}

//Main code for swapping
ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *tmp = head->next->next, *p = head->next;
    head->next->next = head;
    head->next = swapPairs(tmp);
    
    return p;
}

int main(int argc, char* argv[]) {
    int num_nodes;
    scanf("%d", &num_nodes);

    ListNode *head = createLinkedList(num_nodes);
    printf("\n\n");
    printNodes(head);
    printf("\n\n");

    head = swapPairs(head);
    printNodes(head);
    printf("\n");
}
