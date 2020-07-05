class node:
    def __init__(self,data):
        self.data = data
        self.next = None;

class Link_list:
    def __init__(self):
        self.start = None;
    def make_node(self,value):
        if(self.start==None):
            self.start = node(value)
        else:
            temp = self.start
            while(temp.next!=None):
                temp = temp.next
            temp.next = node(value)
    def view_list(self):
        if(self.start==None):
            print("list is empty",end='\n')
        else:
            temp = self.start
            while(temp!=None):
                print(temp.data)
                temp = temp.next


link = Link_list()


link.make_node(2)

link.make_node(8)

link.make_node(6)

link.view_list()
