def solution(A,SUM1):
	curr_sum = A[0]
	sub_array = []
	j = 0
	for i in range(len(A)):
		while(curr_sum>SUM1 and j < i):
			curr_sum = curr_sum - A[j]
			j+=1
		if(curr_sum == SUM1):
				print(A[j:i-1])
				print(j," ",i-1)
		if(curr_sum<SUM1):
			curr_sum = curr_sum + A[i]


A = [15, 2, 4, 8, 9, 5, 10, 23]
SUM1 = 23
solution(A,SUM1)