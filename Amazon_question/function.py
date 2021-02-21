def f(x):
    if abs(x)<=1:
        if x==1:
            return 1
        if(x== -1):
            return -1
        if x==0:
            return 0
    else:
        if x>0:
            return f(x-1) + f(x-2)
        if x<0:
            return f(x+1) + f(x+2)
print (f(int(input())))