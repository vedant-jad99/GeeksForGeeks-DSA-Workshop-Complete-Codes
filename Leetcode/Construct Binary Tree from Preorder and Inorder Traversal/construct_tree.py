"""
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return
the binary tree.
Example:
        Input - preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        Output - [3,9,20,null,null,15,7]
        Explanation - The construcuted binary tree is:
            3
           / \
          9   20
             / \
            15  7
            
 Constraints:
        Time complexity - O()
        Space complexity - O(n) [The output tree space]
        1 <= preorder.length <= 3000
        inorder.length == preorder.length
        -3000 <= preorder[i], inorder[i] <= 3000
        preorder and inorder consist of unique values.
        Each value of inorder also appears in preorder.
        preorder is guaranteed to be the preorder traversal of the tree.
        inorder is guaranteed to be the inorder traversal of the tree.
"""

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None
        
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def construct(preord, inord, noted):
            if preord == []:
                return

            root = TreeNode(preord[0])
            noted.add(preord[0])
            index = inord.index(preord.pop(0))
            
            for i in inord[index::-1]:
                if preord != [] and i == preord[0]:
                    root.left = construct(preord, inord, noted)

            for i in inord[index + 1:]:
                if i in noted:
                    break
                if preord != [] and i == preord[0]:
                    root.right = construct(preord, inord, noted)
            return root
        
        visit = set()
        root = construct(preorder, inorder, visit)
        return root
    
def traverse(root):
    if root is None:
        return
    
    q, out = [root], []
    while q != []:
        ele = q.pop(0)
        if ele == "null":
            out.append(ele)
            continue
        
        out.append(ele.val)
        if ele.left is not None:
            q.append(ele.left)
        else:
            q.append("null")
            
        if ele.right is not None:
            q.append(ele.right)
        else:
            q.append("null")
    return out

def accept_input():
    preorder = input("Preorder: ")
    inorder = input("Inorder: ")
    if preorder.startswith('[') and preorder.endswith(']'):
        if inorder.startswith('[') and inorder.endswith(']'):
            preorder = [int(i.strip()) for i in preorder[1:-1].split(',')]
            inorder = [int(i.strip()) for i in inorder[1:-1].split(',')]
            return preorder, inorder
        else:
            raise ValueError("Sequence not Valid: Must start with [ and end with ]")
    else:
        raise ValueError("Sequence not Valid: Must start with [ and end with ]")
    
if __name__ == "__main__":
    preorder, inorder = accept_input()
    sol = Solution()
    tree = sol.buildTree(preorder, inorder)
    out = traverse(tree)
    
    i = len(out) - 1
    while i > 0:
        if out[i] == "null":
            out.pop()
        else:
            break
        i -= 1
        
    print(out)
