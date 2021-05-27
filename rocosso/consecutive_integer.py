# Python3 program to find
# the ranges of consecutive
# numbers from array

# Function to find
# consecutive ranges
def consecutiveRanges(a, n):

	length = 1
	list = []
	
	# If the array is empty,
	# return the list
	if (n == 0):
		return list
	
	# Traverse the array
	# from first position
	for i in range (1, n + 1):
	
		# Check the difference
		# between the current
		# and the previous elements
		# If the difference doesn't
		# equal to 1 just increment
		# the length variable.
		if (i == n or a[i] - a[i - 1] != 1):
		
			# If the range contains
			# only one element.
			# add it into the list.
			if (length == 1):
				list.append(str(a[i - length]))
			else:
	
				# Build the range between the first
				# element of the range and the
				# current previous element as the
				# last range.
				temp = (str(a[i - length]) +
						" - " + str(a[i - 1]))
				list.append(temp)
		
			# After finding the
			# first range initialize
			# the length by 1 to
			# build the next range.
			length = 1
		
		else:
			length += 1
	return list

# Driver Code.
if __name__ == "__main__":

	# Test Case 1:
	arr1 = [-3,-2,-1,5,6,7,9,11,12,13,15,16]
	n = len(arr1)
	
	ans = consecutiveRanges(arr1, n)
	print(ans)
# 	print ("[", end = "")
# 	for i in range(len(ans)):
	
# 		if(i == len(ans) - 1):
# 			print (ans[i], "]")
# 		else:
# 			print (ans[i], end = ", ")
	
# 	# Test Case 2:
# 	arr2 = [-1, 0, 1, 2, 5, 6, 8]
# 	n = len(arr2)
# 	ans = consecutiveRanges(arr2, n)
	
# 	print ("[", end = "")
	
# 	for i in range (len(ans)):
# 		if(i == len(ans) - 1):
# 			print (ans[i], "]")
# 		else:
# 			print (ans[i], end = ", ")

# 	# Test Case 3:
# 	arr3 = [-1, 3, 4, 5, 20, 21, 25]
# 	n = len(arr3)
# 	ans = consecutiveRanges(arr3, n)
	
# 	print ("[", end = "")
	
# 	for i in range (len(ans)):
# 		if(i == len(ans) - 1):
# 			print (ans[i], "]")
# 		else:
# 			print (ans[i], end = ", ")

# # This code is contributed by Chitranayal
