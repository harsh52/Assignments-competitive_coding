# Python3 implementation of the approach 

# Function to return the number 
# of sub-strings that do not contain 
# the given character c 
def countSubstrings(s, c): 

	# Length of the string 
	n = len(s) 

	cnt = 0
	Sum = 0

	# Traverse in the string 
	for i in range(n): 

		# If current character is different 
		# from the given character 
		if (s[i] != c): 
			cnt += 1
		else: 

			# Update the number of sub-strings 
			Sum += (cnt * (cnt + 1)) // 2

			# Reset count to 0 
			cnt = 0
		
	# For the characters appearing 
	# after the last occurrence of c 
	Sum += (cnt * (cnt + 1)) // 2
	return n*(n+1)//2 - Sum-1

# Driver code 
inp=list(input().split(","))
str1 = inp[0]
x = inp[1]
n = len(str1)

print(countSubstrings(s, c)) 

# This code is contributed 
# by mohit kumar 
