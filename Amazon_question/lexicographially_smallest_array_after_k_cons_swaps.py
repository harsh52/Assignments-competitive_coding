# Python program to find lexicographically minimum 
# value after k swaps. 
def minimizeWithKSwaps(arr, n, k): 

	for i in range(n-1): 

		# Set the position where we we want 
	# to put the smallest integer 
		pos = i 
		for j in range(i+1, n): 

			# If we exceed the Max swaps 
		# then terminate the loop 
			if (j-i > k): 
				break

			# Find the minimum value from i+1 to 
			# max (k or n) 
			if (arr[j] < arr[pos]): 
				pos = j 

		# Swap the elements from Minimum position 
		# we found till now to the i index 
		for j in range(pos, i, -1): 
			arr[j],arr[j-1] = arr[j-1], arr[j] 

		# Set the final value after swapping pos-i 
		# elements 
		k -= pos - i 


# Driver Code 
n, k = 5, 3
arr = [7, 6, 9, 2, 1] 
minimizeWithKSwaps(arr, n, k) 

# Print the final Array 
for i in range(n): 
	print(arr[i], end = " ") 
