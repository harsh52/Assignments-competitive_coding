def solution(A):
    length = len(A)+1
    actual_sum = (length)*(length+1)
    
    actual_sum = actual_sum/2
    #print(actual_sum)
    array_sum = 0
    for i in range(len(A)):
        array_sum = array_sum + A[i]
        #print(array_sum)

   # result = actual_sum - array_sum
    print(int(result))


A = [2,3,1,5]

solution(A)
