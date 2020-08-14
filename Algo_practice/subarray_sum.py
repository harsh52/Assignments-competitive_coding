def solution(A,SUM1):
	curr_sum = 0
	sub_array = []
	j = 0
	for i in range(len(A)+1):
		
		if(curr_sum<SUM1):
			curr_sum = curr_sum + A[i]
			print("1,",curr_sum)
			if(curr_sum==SUM1):
				sub_array=A[j:i]
				#print("gjn")
				print(sub_array)
		elif(curr_sum>SUM1):
			curr_sum = curr_sum - A[j]
			print("2,",curr_sum)
			j += 1
			if(curr_sum==SUM1):
				sub_array=A[j:i]
				#print("gjn")
				print(sub_array)
		#elif(curr_sum==SUM1):
		#	sub_array=A[j:i]
			#print("gjn")
			#print(sub_array)


A = [1, 4, 20, 3, 10, 5]
SUM1 = 33
solution(A,33)