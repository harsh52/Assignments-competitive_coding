def solution(S):
	hash1 = dict()
	count = 0
	ans = -0
	ans_final = 0
	if(len(S)==1):
		print("0")
		pass
	else:
		for i in range(len(S)):
			#print(S[i])
			if(S[i] in hash1):
				#print("T")
				value = hash1[S[i]]
				hash1[S[i]] =  i
				if(value > i):
					ans = value - i

					count = 0
				else:
					ans = i - value
					if(ans>ans_final):
						ans_final = ans
					count = 0
					#print(ans_final)


			else:
				hash1[S[i]] = i
				count = count + 1

	if(count >= ans_final):
		if(count==1):
			count= count + 1
			#print(count)
			return(count)
		#print(count)
		return(count)
		
	else:
		#print(ans_final)
		if(ans_final==1):
			ans_final= ans_final + 1
			#print(ans_final)
			return(ans_final)
		
		return(ans_final)



S = "cdd"
#print(len(S))

solution(S)