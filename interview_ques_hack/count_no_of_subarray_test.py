# Python 3 program to count number of sub-arrays
# with even sum using an efficient algorithm
# Time Complexity - O(N)
# Space Complexity - O(1)
def countEvenSum(arr, n):

	# A temporary array of size 2. temp[0] is
	# going to store count of even subarrays
	# and temp[1] count of odd.
	# temp[0] is initialized as 1 because there
	# a single even element is also counted as
	# a subarray
	temp = [1, 0]

	# Initialize count. sum is sum of elements
	# under modulo 2 and ending with arr[i].
	result = 0
	sum = 0

	# i'th iteration computes sum of arr[0..i]
	# under modulo 2 and increments even/odd 
	# count according to sum's value
	for i in range( n):
		
		# 2 is added to handle negative numbers
		sum = ( (sum + arr[i]) % 2 + 2) % 2

		# Increment even/odd count
		temp[sum]+= 1

	# Use handshake lemma to count even subarrays
	# (Note that an even cam be formed by two even
	# or two odd)
	result = result + (temp[0] * (temp[0] - 1) // 2)
	result = result + (temp[1] * (temp[1] - 1) // 2)

	return (result//2)

# Driver code
if __name__ == "__main__":
	
	#arr = [1,2,3,4]
	loop = int(input())
	while(loop != 0):
		n,k = map(int,input().split())
		arr = list(map(int,input().split()))
		#n = len(arr)
		#print(n)
		print(countEvenSum (arr, n))
		loop = loop - 1

