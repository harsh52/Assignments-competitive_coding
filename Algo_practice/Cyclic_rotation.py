#from collections import deque

def solution(A,K):

    #another method using deque
    #A = deque(A)
    #A.rotate(K)
    
    A = A[-K:]+A[:-K]
    print(A)
    return A

A = [1, 1, 2, 3, 5]
K = 40
solution(A,K)
