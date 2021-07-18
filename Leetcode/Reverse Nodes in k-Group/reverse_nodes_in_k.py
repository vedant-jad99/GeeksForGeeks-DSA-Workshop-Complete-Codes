"""
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

For example and constraints - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3818/

Time complexity - O(n)
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        start, temp = head, head
        var = k - 1
        
        while var > 0 and head is not None:
            head = head.next
            var -= 1
        
        if head is None:
            return temp
        
        p, start.next = temp.next, None
        while temp is not head:
            q = p.next
            p.next = temp
            temp = p
            p = q
        
        start.next = self.reverseKGroup(p, k)
        return head
