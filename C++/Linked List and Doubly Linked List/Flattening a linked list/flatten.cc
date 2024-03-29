/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
Example:
		Input - 
				5 -> 10 -> 19 -> 28
				|     |     |     | 
				7     20    22   35
				|           |     | 
				8          50    40
				|                 | 
				30               45
		Output - 5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50.
		Explanation - The resultant linked lists has every node in a single level.

		Input -
				5 -> 10 -> 19 -> 28
				|          |                
				7          22   
				|          |                 
				8          50 
				|                           
				30              
		Output - 5->7->8->10->19->20->22->30->50

Constraints:
		Time complexity - O(mn)
		Space complexity - O(mn)
		0 <= N <= 50
		1 <= Mi <= 20
		1 <= Element of linked list <= 10^3
*/

#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

//The problem can treated as merging two sorted linked list. Every sublist is sorted list.
//For merging the nodes, we will use sentinel node. And for every adjacent node, we will merge them.
Node *merge(Node *a, Node *b) {
	Node *head = new Node(1), *ans = head, *temp;
	while(a != NULL && b != NULL) {
		if(a->data < b->data) {
			temp = a->bottom;
			head->bottom = a;
			a->bottom = NULL;
			a = temp;
		}
		else {
			temp = b->bottom;
			head->bottom = b;
			b->bottom = NULL;
			b = temp;
		}
		head = head->bottom;
	}
	if(a != NULL)
		head->bottom = a;
	else
		head->bottom = b;

	return ans->bottom;
}
Node *flatten(Node *root)
{
    Node *head = new Node(-1);
	while(root != NULL) {
		head = merge(head, root);
		root = root->next;
	}
	return head->bottom;
}
