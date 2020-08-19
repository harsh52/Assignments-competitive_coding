def solution(A):
	max1 = 0
	for i in range(len(A)):
		p = A[i:]
		for j in range(len(p)):
			if(A[i]<=A[j]):
				if(max1<j-1):
					max1 = j-1
					
	print(max1)

A = [34, 8, 10, 3, 2, 80, 30, 33, 1]
solution(A)

