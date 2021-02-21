# Dynamic Programming Python implementation of Min Cost Path
# problem

import sys
INF = sys.maxsize

def minCost(cost): 
  
    # dist[i] stores minimum 
    # cost to reach station i 
    # from station 0. 
    dist=[0 for i in range(N)] 
    for i in range(N): 
        dist[i] = INF 
    dist[0] = 0
   
    # Go through every station 
    # and check if using it 
    # as an intermediate station 
    # gives better path 
    for i in range(N): 
        for j in range(i+1,N): 
            if (dist[j] > dist[i] + cost[i][j]): 
                dist[j] = dist[i] + cost[i][j] 
   
    return dist[N-1]


# Driver program to test above functions
'''
cost = [[1, 2, 3],
		[4, 8, 2],
		[1, 5, 3]]
'''

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

print(minCost(graph))

# This code is contributed by Bhavya Jain
