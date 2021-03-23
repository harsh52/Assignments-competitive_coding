# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:

    def preorderTraversal(self, root: TreeNode) -> List[int]:
        #list1 = []
        #Solution.helper(root,list1)
        #return(list1)
        stack = deque()
        list_pre = []
        list_in = []
        list_post = []
        temp = (root,1)
        stack.append(temp)
        while(len(stack) != 0):
            root,state = stack[-1]
            if(root == None):
                return
            if(state == 1): #pre state+1 left
                root,state = stack.pop()
                state = state + 1
                list_pre.append(root.val)
                temp = (root,state)
                stack.append(temp)
                if(root.left != None):
                    temp = (root.left,1)
                    stack.append(temp)
                    
            elif(state == 2): #in state+1 right
                root,state = stack.pop()
                state = state + 1
                list_in.append(root.val)
                temp = (root,state)
                stack.append(temp)
                if(root.right != None):
                    temp = (root.right,1)
                    stack.append(temp)
            else: #post 
                root,state = stack.pop()
                
                list_post.append(root.val)
                
        return(list_pre)
                
                
                
        
        
        