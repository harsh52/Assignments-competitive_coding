# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def aremirror(root,root2):
        if(root == None and root2 == None):
            return(1)
        elif(root != None and root2 != None):
            if(root.val == root2.val):
                return(aremirror(root.left,root2.right) and aremirror(root.right,root2.left))
            
        else:
            return(0)
            
    def isSymmetric(self, root: TreeNode) -> bool:
        
        '''
        queue1 = deque()
        queue2 = deque()
        if(root == None):
            return(0)
        queue1.append(root)
        queue2.append(root)
        
        while(len(queue1) != 0):
            for i in range(0,len(queue1)):
                toor1 = queue1.popleft()
                toor2 = queue2.popleft()
                if(toor1.val != toor2.val):
                    return(0)
                if(toor1.left != None and toor2.right != None):
                    queue1.append(toor1.left)
                    queue2.append(toor2.right)
                if(toor1.right != None and toor2.left != None):
                    queue1.append(toor1.right)
                    queue2.append(toor2.left)
                    
                if(toor1.left == None and toor2.right != None):
                    return(0)
                
                if(toor1.left != None and toor2.right == None):
                    return(0)
                
                if(toor1.right == None and toor2.left != None):
                    return(0)
                if(toor1.right != None and toor2.left == None):
                    return(0)
        return(1)
        '''

                    