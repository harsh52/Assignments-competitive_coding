import sys
INF = sys.maxsize

def mm(i,j,graph):
    if(i==j):
        return 0
    
    if(i+1 == j ):
        return(graph[i][j])
    
    min1 = graph[i][j]
    for k in range(i+1,j):
        temp = mm(i,k,graph) + mm(k,j,graph)
        if(temp < min1):
            min1 = temp
    
    return min1



#user Input
# N = number of cities
# M = max no of bridges i can take
# K = total no of bridges 
s = 0
N,M,K = map(int,input().split())
c = list(map(int,input().split()))
b = [list(map(int, input().split())) for i in range(M)]

graph = [[INF for j in range(N)]
			for i in range(N)]


#fill the graph with appropate input
for i in range(N - 1):
    graph[i][i+1] = c[i]
#update the graph with bridge
for i in b:
    val1 = i[0] - 1
    val2 = i[1] - 1
    val3 = i[2] 
    if(graph[val1][val2] > val3 and M != 0):
        graph[val1][val2] = val3
        M = M - 1
#print(s)
#print(N-1)
#print(graph)
#print(N)
print(mm(s, N-1,graph))