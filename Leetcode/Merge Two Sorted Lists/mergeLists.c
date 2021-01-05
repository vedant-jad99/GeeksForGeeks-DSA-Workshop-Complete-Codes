/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together 
the nodes of the first two lists.
Ex. Input - l1 = [1, 2, 3]; l2 = [1, 3, 4]
    Output - [1, 1, 2, 3, 3, 4]
    Explanation - merge the lists in sorted order

Constraints - 

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.

Solution complexity -
    Time complexity - O(n1 + n2)
    Space complexity - O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#define nullptr NULL

typedef struct list {
    int val;
    struct list *next;
}ListNode;

ListNode *createNode(int x) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->val = x;
    node->next = nullptr;
    return node;
}
ListNode *linked_list() {
    int val; 
    scanf("%d", &val);
    if(val == 101)
        return nullptr;
    ListNode *head = createNode(val);
    head->next = linked_list();
    return head;
}
void printList(ListNode *head) {
    while(head->next) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("%d", head->val);
}

//Solution
ListNode *merge(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;
        
    ListNode *head = nullptr, *p;
    while(l1 != nullptr && l2 != nullptr) {
        if(l1->val < l2->val) {
            if(head == nullptr) {
                head = l1;
                p = head;
                l1 = l1->next;
            }
            else {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
        }
        else {
            if(head == nullptr) {
                head = l2;
                p = head;
                l2 = l2->next;
            }
            else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
    }
    while(l1) {
        p->next = l1;
        p = p->next;
        l1 = l1->next;
    }
    while(l2) {
        p->next = l2;
        p = p->next;
        l2 = l2->next;
    }
    return head;
}

int main() {
    ListNode *l1, *l2;
    l1 = linked_list();
    l2 = linked_list();

    ListNode *head = merge(l1, l2);
    printf("\n\n");
    printList(head);

    return 0;
}
