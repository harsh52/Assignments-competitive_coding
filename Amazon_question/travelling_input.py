import sys
INF = sys.maxsize

N,M,K = map(int,input().split())
c = list(map(int,input().split()))
b = [list(map(int, input().split())) for i in range(M)]

graph = [[INF for j in range(N)]
			for i in range(N)]



print(N,M,K)
print(c)
print(b)
print(graph)

for i in range(N - 1):
    graph[i][i+1] = c[i]
    

print(graph)

print("\n")

for i in b:
    val1 = i[0] - 1
    val2 = i[1] - 1
    val3 = i[2] 
    #print(graph[val1][val2])
    #print("\n graph upper")
    #print(i[0]-1,i[1]-1,i[2])
    if(graph[val1][val2] > val3 and M != 0):
        graph[val1][val2] = val3
        M = M - 1

        #print(b[i][j])
print(graph)