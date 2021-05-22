'''
Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in 
the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example:
        Input - root = [1,2,5,3,4,null,6]
        Output - root = [1,null,2,null,3,null,4,null,5,null,6]
        Explanation - Binary Tree =             Flattened =
                            1                        1
                           / \                        \
                          2   5                        2
                         / \   \                        \ 
                        3  4    6                        3
                                                          \
                                                           4
                                                            \
                                                             5
                                                              \
                                                               6
        Input - []
        Output - []

Constraints:
        Time complexity - O(n*logn)
        Space complexity - O(1)
        The number of nodes in the tree is in the range [0, 2000].
        -100 <= Node.val <= 100

Topic Tags - BST
'''

class TreeNode:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None

class Tree:
    def __init__(self):
        self.root = None
    def buildTree(self):
        print("Keep entering node values. If the null, enter 'null'")
        self.root = self.nodes()
    def nodes(self):
        val = input("Enter value: ")
        if val == "null":
            return None
        
        node = TreeNode(val)
        node.left = self.nodes()
        node.right = self.nodes()
        return node

def print_tree(root):
    if root is not None:
        print_tree(root.left)
        print(root.data, end=", ")
        print_tree(root.right)

def flatten(root):
    """
    Do not return anything, modify root in-place instead.
    """
    if root is not None:
        if root.left is None:
            flatten(root.right)
        else:
            t = root.right
            root.right, root.left = root.left, None
            attach(root.right, t)
            flatten(root.right)
                
def attach(root, t):
    if root.right is None:
        root.right = t
    else:
        attach(root.right, t)


if __name__ == '__main__':
    tree = Tree()
    tree.buildTree()
    print_tree(tree.root)

    flatten(tree.root)
    print()
    print_tree(tree.root)