"""
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the 
reversed list.
Example:
        Input - head = [1,2,3,4,5], left = 2, right = 4
        Output - [1,4,3,2,5]
        Explanation - 1->2->3->4->5 ==> 1->4->3->2->5
        
        Input - head = [5], left = 1, right = 1
        Output - [5]
        
Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        The number of nodes in the list is n.
        1 <= n <= 500
        -500 <= Node.val <= 500
        1 <= left <= right <= n

Follow up: Could you do it in one pass?
"""

#One pass solution.

class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None
    
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if left == right:
            return head
        
        sentinel, count = ListNode(), 1
        sentinel.next, curr = head, sentinel
        while count != left:
            curr = curr.next
            count += 1
        
        start, curr.next, prev = curr.next, None, None
        temp = start
        while count != right:
            q = start.next
            start.next = prev
            prev = start
            start = q
            count += 1
        
        temp.next = start.next
        start.next= prev
        curr.next = start
        
        return sentinel.next
