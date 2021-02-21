# Python3 code for printing Minimum Cost
# Simple Path between two given nodes
# in a directed and weighted graph
import sys
INF = sys.maxsize

#V = 5
K = 5
INF = sys.maxsize

# Function to do DFS through the nodes
def minimumCostSimplePath(u, destination, 
						visited, graph,N):

	# Check if we find the destination
	# then further cost will be 0
	if (u == destination):
		return 0

	# Marking the current node as visited
	visited[u] = 1

	ans = INF

	# Traverse through all
	# the adjacent nodes
	for i in range(N):
	    #if(graph[u][i] != INF and bridge[u][i] != INF and bridge[u][i] < graph[u][i] and not visited[i] and M!=0):
	     #   M = M - 1
	     #   curr = minimumCostSimplePath(i,destination,visited, graph,bridge,M)
	      #  if(curr < INF and graph[u][i] != INF and bridge[u][i] != INF and bridge[u][i] < graph[u][i] and M!=0):
	     #       ans = min(ans,bridge[u][i]+curr)
	            
		if (graph[u][i] != INF and not visited[i]):

			# Cost of the further path
			curr = minimumCostSimplePath(i, destination, 
										visited, graph,N)

			# Check if we have reached the destination
			if (curr < INF):

				# Taking the minimum cost path
				ans = min(ans, graph[u][i] + curr)
			
	# Unmarking the current node
	# to make it available for other
	# simple paths
	visited[u] = 0

	# Returning the minimum cost
	return ans
	
# Driver code

	
# Initialising the graph

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

# Marking all nodes as unvisited
visited = [0 for i in range(N)]

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

# Initialising the edges
#graph[0][1] = 1
#graph[0][3] = 1
#graph[1][2] = 2
#graph[2][3] = 1
##graph[3][4] = 4

#
#graph[0][2] = 2
	
# Source and destination

#t = 4
#M = 1
#bridge = [[INF for j in range(K)] for i in range(K)]
#bridge[0][1] = 3
#bridge[0][2] = 2
#bridge[2][3] = 1
# Marking the source as visited
visited[s] = 1
	
print(minimumCostSimplePath(s, N-1, visited, graph,N))

# This code is contributed by rutvik_56
