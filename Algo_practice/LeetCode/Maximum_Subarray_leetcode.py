'''
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        csum = nums[0]
        osum = nums[0]
        arr = nums
        for i in range(1,len(arr)):
            
            if(csum < 0):
                csum = arr[i]
            else:
                csum = csum + arr[i]
            if(csum > osum):
                osum = csum
        return(osum)