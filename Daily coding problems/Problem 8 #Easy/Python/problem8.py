#Driver code
class Node:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None


def create():
    n = int(input())
    if n == -1:
        return None
    root = Node(n)
    root.left = create()
    root.right = create()
    return root

def print_tree(root):
    if root != None:
        print(root.val, end=" ")
        print_tree(root.left)
        print_tree(root.right)

#Main solution code
def count_unival(root):
    if root == None:
        return True, 0
    if root.left == None and root.right == None:
        return True, 1

    left_val, l_val = count_unival(root.left)
    right_val, r_val = count_unival(root.right)
    if right_val and left_val:
        if (root.left == None and root.val == root.right.val) or (root.right == None and root.val == root.left.val) or (root.val == root.left.val and root.val == root.right.val):
            return True, 1 + l_val + r_val
    return False, l_val + r_val
    
#Driver code
if __name__ == '__main__':
    tree = create()
    print("\n")
    print_tree(tree)
    print("\n")
    context, count = count_unival(tree)
    print(count)
