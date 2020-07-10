


def solution(X,Y,D):
    dist = Y-X
    value = dist/D
    #print(value)
    
    if(isinstance(value,float)):
        #print(round(value)+1)
        return round(value)+1
    else:
        #print(value+1)
        #print(round(value)+1)
        return round(value)
    
        

solution(10,85,30)
