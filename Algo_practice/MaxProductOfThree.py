def solution(A):
	A.sort()
	A.reverse()
	print(A)
	if(A[len(A)-1]<0 and A[len(A)-1]<0 and abs(A[0]) < abs(A[len(A)-1]) and abs(A[1]) < abs(A[len(A)-2])):
		print(ans)
		ans = A[len(A)]*A[len(A)-1]*A[2]
	else:
		
		ans = A[0]*A[1]*A[2]
		print(ans)
		return ans
	
A = [-5,5,-5,4]
solution(A)