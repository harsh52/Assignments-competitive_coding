#run on leetcode

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        current = head
        #print(current)
        while(current != None):
            #print("1")
            next1 = current.next
            current.next = prev
            prev = current
            current = next1
            #print(next1.val)
        head1 = prev
        return(head1)