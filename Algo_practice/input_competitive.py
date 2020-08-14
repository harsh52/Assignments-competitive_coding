'''

Suppose the input is of the following form

5 7 19 20
and we want separate variables to reference them. what we want is:

a = 5
b = 7
c = 19
d = 20
so, we can create a function named as get_ints() as follows:

'''

import sys 
def get_ints(): return map(int, sys.stdin.readline().strip().split()) 
  
a,b,c,d = get_ints() 




'''

1 2 3 4 5 6 7 8
and we want that a single variable will hold the whole list of integers. What we want is :

Arr = [1, 2, 3, 4, 5, 6, 7, 8]
So, here we will create a function named as get_list() as follows:

'''
import sys 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 
  
Arr = get_list() 