"""
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
Example:
        Refer the question here - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3797/

Constraints:
        Time complexity - O(n)
        Space complexity - O(h) [Recursion stack]
        The number of nodes in the tree is in the range [2, 10^5].
        -10^9 <= Node.val <= 10^9
        All Node.val are unique.
        p != q
        p and q will exist in the tree.
"""

ans = None
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def helper(root, p, q):
            if root == None:
                return False
                
            global ans
            left = helper(root.left, p, q)
            right = helper(root.right, p, q)
            
            if left and right:
                ans = root
                return False
            if root is p or root is q:
                ans = root
                return True
            if left or right:
                return True
            
            return False
        
        global ans
        ans = None
        helper(root, p, q)
        return ans
