'''

You are given a number n.

A supernatural number is a number whose product of digits is equal to n, and in this number there is no digit 1.

Count the number of supernatural numbers for a given n.

Input

Contains a single integer n, 1 <= n <= 100.

Output

Print the number of supernatural numbers.

'''

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
