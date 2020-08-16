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



'''
When you want to take input of string
Suppose the input is of the following form

GeeksforGeeks is the best platform to practice Coding.
and we want that a single reference variable will hold this string. What we want is :

string = "GeeksforGeeks if the best platform to practice coding."
So, here we will create a function named as get_string() as follows:
'''

import sys 
def get_string(): return sys.stdin.readline().strip() 
  
string = get_string() 


# basic method of input output 
# input N 
#For taking single input
n = int(input()) 




#For strings -
I love python
l = list(input().split())
#The value of l will be l=['I','love','python']
