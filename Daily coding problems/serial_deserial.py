class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def create():
    try:
        n = int(input())
        if n != 0:
            root = Node(n)
            root.left = create()
            root.right = create()
        else:
            return None
        return root
    except ValueError:
        print("\nEnter only numbers.\n")
        return create()

def print_tree(root):
    if(root != None):
        print(root.val)
        print_tree(root.left)
        print_tree(root.right)

def serialize(root):
    s = ""
    if root != None:
        s = s + str(root.val) + ','
        s = s + str(serialize(root.left))
        s = s + str(serialize(root.right))
    else:
        s += '-1,'
    return s

def deserialize(s):
    s = s.split(',')
    return create_deserial(s)
    
def create_deserial(s):
    if len(s) != 0:
        root = None
        n = int(s.pop(0))
        if n != -1:
            root = Node(n)
            root.left = create_deserial(s)
            root.right = create_deserial(s)
        return root


if __name__ == '__main__':
    root = create()
    print()
    print_tree(root)
    # serial = serialize(root)[:-1]
    # print("\n{}".format(serial)) 
    # d_root = deserialize(serial)
    # print("\n")
    # print_tree(d_root)
    assert deserialize(serialize(root)).left.left.val == root.left.left.val