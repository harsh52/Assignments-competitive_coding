# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:  
        
    def inorderTraversal(self, root:  TreeNode) -> List[int]:

        stack = deque()
        list2 = []
        curr = root
        while(curr!= None or len(stack)!=0):
            if(curr!=None):
                stack.append(curr)
                curr = curr.left
            else:
                curr = stack[-1]
                temp = stack.pop()
                list2.append(temp.val)
                curr = curr.right
                
        return(list2)
        