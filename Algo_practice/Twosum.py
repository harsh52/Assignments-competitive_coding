'''
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

def solution(A,target):
	hash1 = dict()
	for i in range(len(A)):
		hash1[A[i]] = i
	print(hash1)
	lenght_dict = len(hash1.keys())
	print(lenght_dict)
	count = 0
	for key,value in hash1.items():
		index1 = hash1[key]
		key1 = target - key
		count += 1
		if(key1==key):
			continue
		else:
			index2 = hash1.get(key1)
			if(index2!= None):
				out_list = [index1,index2]
				print(out_list)
				return(out_list)
				break


A = [3,2,4,3]


target = 6

solution(A,target)
