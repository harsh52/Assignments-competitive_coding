l = [5,4,3,2,1,0,-1,-2,-3]
initial_flag = 12
final_flag = 15
def hillvalley(l):
	for i in range(len(l)-1):
		#print(l[i+1])
		if(l[i+1]-l[i]>0):
			initial_flag = 0
			final_flag = 1
		else:
			final_flag = 0
	if(initial_flag == final_flag):
		#return True
		print("TRUE")
	else:
		#return False
		print("FALSE")


hillvalley(l)