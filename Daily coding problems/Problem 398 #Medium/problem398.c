#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int data;
    struct list_node *next;
} ListNode;

ListNode *create_node(int data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}
ListNode *make_linked_list(int arr_len, int *arr) {
    ListNode *head = NULL, *temp;
    for (int i = 0; i < arr_len; i++) {
        ListNode *node = create_node(arr[i]);
        if (head == NULL) {
            head = node;
            temp = head;
        } else {
            temp->next = node;
            temp = node;
        }
    }
    return head;
}
void print_linked_list(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ListNode *delete_kth_node_from_end(ListNode *head, int *k) {
//     if(head) {
//         head->next = delete_kth_node_from_end(head->next, k);
//         (*k)--;
//         if(*k == 0) {
//             ListNode *temp = head->next;
//             free(head);
//             return temp;
//         }
//     }
//     return head;
// }
//Approach 2: Two Pointers
ListNode *delete_kth_node_from_end(ListNode *head, int k) {
    ListNode *slow = head, *fast = head;
    while(k) {
        fast = fast->next;
        k--;
    }
    if(fast == NULL) {
        ListNode *temp = head->next;
        free(head);
        return temp;
    }
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main() {
    int arr[] = {95529, 57324, 40134, 64211, 21431, 40187, 54154, 58904, 11000, 45994, 71577, 32593, 15562, 7219, 12135, 26553, 50227, 47356, 52690, 8238, 28406, 55590, 54547, 13923, 16455, 8258, 94082, 74098, 96173, 33121, 35295, 83680, 99120, 77927, 35439, 21420, 30398, 59858, 50308, 56989, 28049, 33484, 96432, 78772, 26540, 89650, 4716, 12345, 42438, 21545, 78799, 46121, 15125, 54919, 88799, 4375, 23677, 64515, 73320, 78308, 10302, 40733, 219, 4527, 26648, 37440, 35691, 87479, 17632, 60294, 92499, 57195, 33900, 94086, 96709, 33132, 108, 26776, 2934, 27727, 31728, 9008, 57466, 45174, 86810, 96073, 20753, 99641, 49192, 45036, 42243, 17926, 7298, 23969, 55154, 86749, 95816, 68964, 58016, 87310};
    int k = 9;
    int arr_len = sizeof(arr) / sizeof(int);
    ListNode *head = make_linked_list(arr_len, arr);
    print_linked_list(head);
    head = delete_kth_node_from_end(head, k);

    print_linked_list(head);
    return 0;
}
