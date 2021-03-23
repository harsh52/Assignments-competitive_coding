# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    '''
    def helper(root,list1):
        if(root == None):
            return
        Solution.helper(root.left,list1)
        #print(root.val)
        list1.append(root.val)
        Solution.helper(root.right,list1)
    '''    
        
    def inorderTraversal(self, root:  TreeNode) -> List[int]:
        
        #list1 = []
        #Solution.helper(root,list1)
        #return(list1)
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
        