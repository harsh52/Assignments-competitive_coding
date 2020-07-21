class node:
    def __init__(self,data):
        self.data = data
        self.left = None;
        self.right = None;

			
class tree:
    
    def __init__(self):
        self.start = None;
    
    def make_node(self,Node,data):
        
        if(Node == None):
            Node = node(data)
            if(self.start == None):
                self.start = Node
            return Node
        
        if(Node.data>data):
            Node.left = self.make_node(Node.left,data)
        elif(Node.data<=data):
            Node.right = self.make_node(Node.right,data)
            
        return Node
    
    def inorder(self,root):
        if(root==None):
            return
        self.inorder(root.left)
        print(root.data)
        self.inorder(root.right)
		
BST = tree()
BST.make_node(BST.start,2)
BST.make_node(BST.start,3)
BST.make_node(BST.start,4)
BST.make_node(BST.start,5)

BST.inorder(BST.start)