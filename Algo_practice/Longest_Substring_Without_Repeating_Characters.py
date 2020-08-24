def solution(A):
	hash1 = dict()
	j=0
	count = 0
	temp = 0
	for i in range(len(A)):
		if(hash1.get(A[i])!=None):
			j=hash1[A[i]]
		if(A[j]==A[i]):
			temp = 1 
			j += 1
			if(temp>count):
				count = temp
		if(hash1.get(A[i]) == None):
			hash1[A[i]]=i
			temp=0
	print(count)
	return count

A = "abcabcbb"
solution(A)