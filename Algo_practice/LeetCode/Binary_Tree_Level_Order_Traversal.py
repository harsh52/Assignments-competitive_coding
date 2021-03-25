# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        queue = deque()
        ans = []
        if(root == None):
            return ans
        
        queue.append(root)
        
        while(len(queue) != 0):
            list1 = []
            for i in range(0,len(queue)):
                toor = queue.popleft()
                list1.append(toor.val)
                if(toor.left != None):
                    queue.append(toor.left)
                if(toor.right != None):
                    queue.append(toor.right)
                
            ans.append(list1)
        return(ans)
        
        
        