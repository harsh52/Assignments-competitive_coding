# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        queue = deque()
        count = 0
        if(root == None):
            return(0)
        queue.append(root)
        while(len(queue) != 0):
            for i in range(0,len(queue)):
                toor = queue.popleft()
                if(toor.left != None):
                    queue.append(toor.left)
                if(toor.right != None):
                    queue.append(toor.right)
            count += 1
            
        return(count)
        
        
        