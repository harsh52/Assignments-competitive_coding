'''
Given an array arr[] of integers and an integer K, the task is to find the greatest contiguous sub-array of size K. Sub-array X is said to be greater than sub-array Y if the first non-matching element in both the sub-arrays has a greater value in X than in Y.
'''

def solution(A,K):
	final = []
	length = len(A)-K+1
	print(length)
	for i in range(len(A)):
		j = i
		#L=K+j
		#print(j)
		temp1 = A[j:K+j]
		#print("temp1:",temp1)
		temp2 = A[j+1:K+j+1]
		#print("temp2:",temp2)
		if(len(temp1) and len(temp2) >= K):
			for p,q in zip(temp1,temp2):
				if(p>q):
					final = temp1
					#print("final:",final)
				elif(p<q):
					final = temp2
					#print("final:",final)
				#print(final)
		#temp1 = []
		#temp2 = []
	#print(final)


A = [1, 4, 3, 2, 5]
K = 4
solution(A,K)
