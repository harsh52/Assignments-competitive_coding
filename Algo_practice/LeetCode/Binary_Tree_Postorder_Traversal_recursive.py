# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(root,list1):
        if(root == None):
            return
        Solution.helper(root.left,list1)
        Solution.helper(root.right,list1)
        list1.append(root.val)
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        list1 = []
        Solution.helper(root,list1)
        return(list1)