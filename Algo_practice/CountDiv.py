def solution(A,B,K):
	count = 0
	for i in range(A,B):
		if(i%K==0):
			count += 1
	#print(count)
	return count

solution(6,11,2)