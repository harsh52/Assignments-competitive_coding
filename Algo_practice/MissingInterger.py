'''
Write a function:

    def solution(A)

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].


'''



def solution(A):
	A.sort()
	set1 = set(A)
	#print(set1)
	#set1.sort()
	j = 0
	for i in set1:
		j += 1
		if(i!=j):
			#print(j)
			return j
		elif(j==len(set1)):
			#print(j+1)
			if(j+1<0):
				return 1
			else:
				return(j+1)

A = [-1, -3]
solution(A)