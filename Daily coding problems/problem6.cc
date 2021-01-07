#include <iostream>
#include <cstdlib>
#define null nullptr

typedef struct XOR {
    int val;
    struct XOR *both = null;
}XORList;

XORList *add(int element, XORList *head) {
    if(head) {
        XORList *prev = null, *next, *q = head;
        while(q->both && prev != q->both) {
            next = (XORList*)((uintptr_t)q->both ^ (uintptr_t)prev);
            prev = q;
            q = next;
        }
        XORList *newNode = (XORList*)malloc(sizeof(XORList));
        newNode->val = element;
        q->both = (XORList*)((uintptr_t)prev ^ (uintptr_t)newNode);
        newNode->both = (XORList*)((uintptr_t)q ^ (uintptr_t)null);
        return head;
    }
    head = (XORList*)malloc(sizeof(XORList));
    head->val = element;
    return head;
}
XORList *getIndex(int index, XORList *head) {
    XORList *prev = null, *next;
    while(index && (head->both && prev != head->both)) {
        index--;
        next = (XORList*)((uintptr_t)head->both ^ (uintptr_t)prev);
        prev = head;
        head = next;
    }
    if(index > 0)
        return null;
    return head;
}
void traverse(XORList *head) {
    if(!head)
        return;
    XORList *prev = null, *next;
    while(head->both && prev != head->both) {
        printf("%d ", head->val);
        next = (XORList*)((uintptr_t)head->both ^ (uintptr_t)prev);
        prev = head;
        head = next;
    }
    printf("%d", head->val);
    printf("\n\n");
}

int main() {
    XORList *head = null;
    int n, scan, index;
    scanf("%d", &n);

    while(n) {
        scanf("%d", &scan);
        head = add(scan, head);
        n--;
    }
    traverse(head);
    scanf("%d", &index);
    XORList *indexNode = getIndex(index, head);
    if(indexNode)
        printf("%d\n\n", indexNode->val);
    else
        printf("Index exceeding length of list.\n\n");
    return 0;
}