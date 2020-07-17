def solution(X,A):
	for i in range(len(A)):
		
		if(A[i]==X):
			#print(i)
			return(i)
	return(-1)


A=[1,3,1,4,2,3,5,4]
solution(A,11)