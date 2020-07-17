



'''
Task description

A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

We can split this tape in four places:

        P = 1, difference = |3 − 10| = 7
        P = 2, difference = |4 − 9| = 5
        P = 3, difference = |6 − 7| = 1
        P = 4, difference = |10 − 3| = 7

Write a function:

    def solution(A)

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−1,000..1,000].


'''



def solution(A):
	total = sum(A)
	left_sum = 0
	right_sum = 0
	temp2 = 0
	temp = total

	if(len(A)==2):
		#print(abs(A[0]-A[1])	)
		return(abs(A[0]-A[1]))
	if(total<0):
		temp = abs(sum(A))
		for i in range(len(A)):
		
			#till = temp + A[i]
			left_sum = left_sum + A[i]
			#print(left_sum)
			right_sum = total - left_sum
			#print(right_sum)
			diff = right_sum - left_sum
			#print(diff)
			if(diff<=temp):
				#print(temp)
				temp = abs(diff)
				
		print(temp)
		return temp

	for i in range(len(A)):
		
		#till = temp + A[i]
		left_sum = left_sum + A[i]
		#print(left_sum)
		right_sum = total - left_sum
		#print(right_sum)
		diff = left_sum - right_sum
		#print(diff)
		if(diff<temp):
			temp = abs(diff)
			#print(temp)
	#print(temp)
	return temp

A = [-2,-3,-4,-1]

solution(A)

