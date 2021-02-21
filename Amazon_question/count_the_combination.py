import sys 
import re

def countSubStr(str, n, x):  
    res = 0; count = 0;  
    for i in range(n):  
        if (str[i] == x):   
            res += ((count + 1) * (n - i));  
            count = 0;  
        else: 
            count+=1;  
   
    return res;  
inp=list(input().split(","))
str1 = inp[0]
x = inp[1]
n = len(str1)

print(countSubStr(str1, n, x))