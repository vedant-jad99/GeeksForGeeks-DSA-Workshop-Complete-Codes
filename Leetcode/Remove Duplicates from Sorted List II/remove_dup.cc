/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only 
distinct numbers from the original list. Return the linked list sorted as well.
Ex. Input - [1, 2, 3, 3, 4, 4, 5]
    Output - [1, 2, 5]
    Explanation - 3 and 4 are repeating, so they are removed.

Ex. Input - [1, 1, 1, 2, 3]
    Output - [2, 3]

Constraints - 
    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.

Solution complexity - 
    Time complexity - O(n)
    Space complexity - O(k), k = number of distinct elements (for 1st)
                       O(1) (for 2nd and 3rd)
*/

#include <iostream>
#include <cstdlib>
#include <map>
#include <iterator>

using namespace std;

typedef struct list {
    int val;
    struct list *next = nullptr;
}ListNode;

ListNode *createNode(int x) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->val = x;
    return node;
}
ListNode *linkedList() {
    int val;
    scanf("%d", &val);
    if(val == 101)
        return nullptr;
    ListNode *head = createNode(val);
    head->next = linkedList();
    return head;
}
void printList(ListNode *head) {
    while(head->next) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
}

//Method 1. Two pass(O(n)) and O(k) space. Very slow
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p = head;
    map<int, int> a;
    map<int, int>::iterator it;
    
    while(p) {
        it = a.find(p->val);
        if(it == a.end())
            a.insert({p->val, 1});
        else
            it->second++;
        p = p->next;
    }
    ListNode *head2 = nullptr, *q = nullptr;
    for(auto x : a) {
        if(x.second == 1) {
            if(!q) {
                q = createNode(x.first);
                head2 = q;
            }
            else {
                q->next = createNode(x.first);
                q = q->next;
            }
        }
    }
    return head2;
}

//Using sentinel node(False head). One pass, no extra space. [O(n), O(1)]
/*ListNode * deleteDuplicates(ListNode *head) {
    ListNode *setinel = new ListNode(0, head);

	ListNode *last_good = setinel;
	while (head)
	{
		if (head->next && head->val == head->next->val)
		{
			while (head->next && head->val == head->next->val)
				head = head->next;
			last_good->next = head->next;
		}
		else
			last_good = last_good->next;
		head = head->next;
	}
	return setinel->next;
}*/

//Recursive approach one pass.
/*ListNode *deleteDuplicates(ListNode *head) {
    if (!(head))
		return nullptr;
	if (!(head->next))
		return head;

	if (head->val == head->next->val)
	{
		while (head->next && head->val == head->next->val)
			head = head->next;
		return deleteDuplicates(head->next);
	}

	head->next = deleteDuplicates(head->next);
	return head;
}*/


int main() {
    ListNode *head = linkedList();
    printf("\n\n");
    printList(head);
    printf("\n\n");
    printList(deleteDuplicates(head));
    printf("\n");
    return 0;
}