'''
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is 
visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as 
argument. 
Example:
        Input - 1 2 3 4 5 6 7 N 8
        Ouput - 1 2 4 5 
        Left view of following tree is 1 2 4 8.
            1
            /\
           2  3
          /\  /\
         4 5 6 7
          \
           8

        Input - 1 3 2
        Output - 1 3

Constraints:
        Time Complexity - O(N)
        Space Complexity - O(H) H = height of tree
        0 <= Number of nodes <= 100
        1 <= Data of a node <= 1000
'''
from collections import deque

x = 0

def rightSideView(root):
    if root is None:
        return []
    
    global x
    x = 0
    right_nodes = []
    Iter(root, right_nodes, 1)
    return right_nodes
    
def Iter(root, nodes, max_level):
    global x
    if root is not None:
        if max_level > x:
            nodes.append(root.data)
            x = max(max_level, x)
        Iter(root.right, nodes, max_level + 1)
        Iter(root.left, nodes, max_level + 1)
    return



class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
  
def buildTree(s):
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    ip=list(map(str,s.split()))
    
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    q.append(root)                            
    size=size+1 
    
    i=1                                       
    while(size>0 and i<len(ip)):
        currNode=q[0]
        q.popleft()
        size=size-1
        
        currVal=ip[i]
        
        if(currVal!="N"):
            currNode.left=Node(int(currVal))
            
            q.append(currNode.left)
            size=size+1
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        if(currVal!="N"):
            currNode.right=Node(int(currVal))
            
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root
    
    
if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        result = rightSideView(root)
        for value in result:
            print(value,end=" ")
        print()