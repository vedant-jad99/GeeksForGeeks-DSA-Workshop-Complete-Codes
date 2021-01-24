#!/usr/bin/env python3
#Program to find the max depth in a binary tree

import re

def print_tree(root):
    if root:
        print_tree(root.left)
        print(root.val)
        print_tree(root.right)

def calc_max_depth(root):
    if root == None:
        return 0
    if root.left == None and root.right == None:
        return 0
    
    left = calc_max_depth(root.left)
    right = calc_max_depth(root.right)
    return max(left, right) + 1


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
    
class Tree:
    def __init__(self, node_val):
        self.root = self.__create__(node_val)
    def __create__(self, node_val):
        pattern = re.compile(r'null')
        if len(node_val) != 0:
            n = node_val.pop(0)
            if pattern.findall(n):
                return None
            root = Node(n.strip())
            root.left = self.__create__(node_val)
            root.right = self.__create__(node_val)
            return root
        else:
            return None
    def Print(self):
        print_tree(self.root)
    def max_depth(self):
        return calc_max_depth(self.root)


if __name__ == '__main__':
    string = input()
    string = string[1:-1].split(',')
    print("Tree - \n\n")
    tree = Tree(string)
    tree.Print()
    print("\n\nMax depth of given binary tree - {}".format(tree.max_depth()))
