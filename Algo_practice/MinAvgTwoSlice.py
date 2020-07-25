

def solution(A):
	min1 = sum(A)
	#print(min1)
	index = 0
	for i in range(len(A)+1):
		for j in range(i+2,len(A)+1):
			#print(i,j)
			list1 = A[i:j]
			print(list1)
			#print(list1)
			lenght = len(list1)
			#print(lenght)
			total = sum(list1)
			avg = total / lenght
			#print(avg)
			if(min1>avg):
				min1 = avg
				index = i+1
				print(index)
	#print(index)
	#return index


A = [4,2,2,5,1,5,8]
solution(A)