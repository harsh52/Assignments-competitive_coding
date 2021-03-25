# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        stack = deque()
        list1 = []
        list2 = []
        temp = (p,q,1)
        stack.append(temp)
        
        p,q,state = stack[-1]
        if(p == None and q == None):
            return(1)
        if(p == None and q != None):
            return(0)
        if(p != None and q == None):
            return(0)
        
        while(len(stack) != 0):
            p,q,state = stack[-1]
            
            if(state == 1): #pre state+1 left
                p,q,state = stack.pop()
                state = state + 1
                #list_pre.append(root.val)
                list1.append(p.val)
                list2.append(q.val)
                temp = (p,q,state)
                stack.append(temp)
                if(p.left != None and q.left != None):
                    temp = (p.left,q.left,1)
                    stack.append(temp)
                elif(p.left == None and q.left != None):
                    return(0)
                elif(p.left != None and q.left == None):
                    return(0)
                    
            elif(state == 2): #in state+1 right
                p,q,state = stack.pop()
                state = state + 1
                #list_in.append(root.val)
                temp = (p,q,state)
                stack.append(temp)
                if(p.right != None and q.right != None):
                    temp = (p.right,q.right,1)
                    stack.append(temp)
                elif(p.right == None and q.right != None):
                    return(0)
                elif(p.right != None and q.right == None):
                    return(0)
            else: #post 
                p,q,state = stack.pop()
                
                #list_post.append(p.val,q.val)
                
        if(list1 == list2):
            print(list1,list2)
            return(1)
        else:
            return(0)
        