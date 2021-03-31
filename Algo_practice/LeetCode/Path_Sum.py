'''
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    stack = deque()
    sum1 = 0
    list1 = []
    def helper(root,targetSum):
        if(root == None):
            return()
        Solution.stack.append(root.val)
        Solution.helper(root.left,targetSum)
        if(root.left == None and root.right == None):
            #print(stack)
            #sum1 = 0
            Solution.sum1 = sum(Solution.stack)
            Solution.list1.append(Solution.sum1)
            sum1 = 0
            
        Solution.helper(root.right,targetSum)
        Solution.stack.pop()
        
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        Solution.helper(root,targetSum)
        
        print(Solution.list1)
        
        for i in range(len(Solution.list1)):
            if(targetSum == Solution.list1[i]):
                #print(Solution.list1[i])
                Solution.list1 = []
                return(1)
        Solution.list1 = []    
        return(0)
        