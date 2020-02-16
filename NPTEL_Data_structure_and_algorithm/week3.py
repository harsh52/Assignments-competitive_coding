
'''

Define a Python function remdup(l) that takes a nonempty list of integers l and removes all duplicates in l, keeping only the first occurrence of each number.

'''

def remdup(l):
    list1 = []
    for i in l:
        if i not in list1:
            list1.append(i)
    return list1
  
 '''
Write a Python function sumsquare(l) that takes a nonempty list of integers and returns a list [odd,even], where odd is the sum of squares all the odd numbers in l and even is the sum of squares of all the even numbers in l.

 '''

list2 = [0,0]
def sumsquare(l):
    for i in l:
        if i%2 != 0:
            p = list2[0]+i*i
            list2[0]= p
        else:
            p = list2[1]+i*i
            list2[1] = p
    return list2
  

'''

A two dimensional matrix can be represented in Python row-wise, as a list of lists: each inner list represents one row of the matrix.

'''
def transpose(m):
    rez = [[m[j][i] for j in range(len(m))] for i in range(len(m[0]))] 
    return rez