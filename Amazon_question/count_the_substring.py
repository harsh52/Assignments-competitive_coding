def countSubStr(str, x): 
    n=len(str)
    res = 0; count = 0;  
    for i in range(n):  
        if (str[i] == x):  
            res += ((count + 1) * (n - i));  
            count = 0;  
        else: 
            count+=1;  
   
    return n*(n+1)//2 - res;  
    
inp=list(input().split(","))
str= inp[0]
x=inp[1]
   
print(countSubStr(str,x))