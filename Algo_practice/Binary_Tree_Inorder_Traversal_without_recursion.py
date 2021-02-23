'''Given the root of a binary tree, return the inorder traversal of its nodes' values.'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        q = collections.deque()
        list1 = []
        while(1):
            while(root != None):
                q.append(root)
                root = root.left
            #if(q == None):
             #   break
            if(q):
                #when we use pop() for stack (LIFO)
                #popleft() for queue (FIFO)
                #root = q.popleft() #FIFO (Queue)
                root = q.pop()#LIFO(stack)
                #print(root.val)
                list1.append(root.val)
                root = root.right
            else:
                break
        return(list1)