"""
Given the root of a binary tree, return the leftmost value in the last row of the tree.
Example:
        Input - [2,1,3]
        Output - [1]
        Explanation - Given binary tree:
            2
           / \
          1   3
          
       Input - [1,2,3,4,null,5,6,null,null,7]
       Output - 7
       
Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        The number of nodes in the tree is in the range [1, 10^4].
        -2^31 <= Node.val <= 2^31 - 1
"""

max_level = -1

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
    
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        def helper(root, level):
            global max_level
            if root is None:
                return None
            if root.left is None and root.right is None and level > max_level:
                max_level = level
                return root.val
                
            max_level = max(max_level, level)
            l_val = helper(root.left, level + 1)
            r_val = helper(root.right, level + 1)
            
            if r_val is not None:
                return r_val
            else:
                return l_val
            return None
        
        global max_level
        max_level = -1
        return helper(root, 0)
