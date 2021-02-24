'''
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if(root == None):
            return 0
        q = collections.deque()
        q.append((root,1))
        
        while(q != None):
            root, depth = q.popleft()
            if(root.left == None and root.right == None):
                return(depth)
            if(root.left != None):
                q.append((root.left,depth + 1))
            if(root.right != None):
                q.append((root.right,depth + 1))
                