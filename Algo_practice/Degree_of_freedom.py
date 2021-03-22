

def degree(arr,l,m,n):
    
    degree_left = 0
    degree_right = 0
    max1 = -900000
    min1 = 900000
    for i in range(m,l-1,-1):
        #print("left",arr[i],end=" ")
        if(arr[i] > max1):
            max1 = arr[i]
        if(arr[i] < min1):
            min1 = arr[i]
            
    degree_left = max1 - min1
    #print("degree_left",degree_left)
    
    max1 = -900000
    min1 = 900000
    for i in range(m+1,n+1):
        #print("right",arr[i],end=" ")
        if(arr[i] > max1):
            max1 = arr[i]
        if(arr[i] < min1):
            min1 = arr[i]
            
    degree_right = max1 - min1
    #print("degree_right",degree_right)
    
    return(max(degree_right + degree_left, degree_left, degree_right))
    
def divide(arr,l,n):
    if(l == n):
        return 0
        
    m = (l+n) // 2
    divide(arr,l,m)
    divide(arr,m+1,n)
    
    return(degree(arr,l,m,n))


#arr = [1,2,1,0,5]
#arr = [1,2,3,2,1]
arr = [1,4,2,3]
l = 0
n = len(arr) - 1
print(divide(arr,l,n))