# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:

        if(root == None):
            return(root)
        queue = deque()
        queue.append(root)
        
        while(len(queue) != 0):
            for i in range(0,len(queue)):
                toor = queue.popleft()
                #list1.append(toor.val)
                
                toor.left,toor.right = toor.right,toor.left
                
                if(toor.left != None):
                    queue.append(toor.left)
                if(toor.right != None):
                    queue.append(toor.right)
            
        
        return(root)
    
        