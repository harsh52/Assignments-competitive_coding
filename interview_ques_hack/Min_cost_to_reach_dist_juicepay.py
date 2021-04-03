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
   
    return(dist[N-1])

N = int(input())
ignore = [int(input()) for i in range(N)]
noe = int(input())
edges = [tuple(map(int,input().split())) for i in range(noe)]
source = int(input())
destination = int(input())

'''
print(N)
print(ignore)
print(noe)
print(edges)
print(source)
print(destination)
'''
count = 0
dict1 = {}
graph = [[INF for j in range(N)] for i in range(N)]
edges2 = []

ignore[:0]=[source]
ignore.append(destination)

#tup = tuple(ignore)

#print(ignore)
temp = 0
for i in range(len(ignore)):
    
    if ignore[i] not in dict1:
        #print("ignore",ignore[i], count)
        dict1[ignore[i]] = count
        count = count + 1
        temp = count
    else:
        continue
#print(dict1)
#dict1[destination] = count + 1
#d1 = {destination: count}
#dict1.update(d1)
dict1[destination] = temp - 1

if(ignore[-2] != destination):
    val = dict1[ignore[-2]]
    dict1[ignore[-2]] = val - 1

#print(dict1)

for i in range(len(edges)):
    n,k,val = edges[i]
    p = dict1[n]
    q = dict1[k]
    edges2.append((p,q,val))

#print(edges2)

for i in range(len(edges2)):
    n,k,val = edges2[i]
    graph[n][k] = val 


#print(graph)
#print(dict1)
print(minCost(graph))