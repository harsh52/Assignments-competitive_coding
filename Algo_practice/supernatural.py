def isprime(n):
    i = 2
    while(i*i<=n):
        if(n%i==0):
            return False
    return True


def solve(n):
    global ans
    if(n<=1):
        return
    if(isprime(n)):
        if(n<10):
            ans = (ans+1)%101
            return ans
    if(n<10):
        ans = (ans+1)%101
    for j in range(2,10):
        if(n%j==0):
            solve(n/j)




a = int(input())

ans = 0
solve(a)
print(ans,end='\n')
