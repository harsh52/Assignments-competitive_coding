# Python3 program to print all paths of
# source to destination in given graph
from typing import List
from collections import deque

# Utility function for printing
# the found path in graph
def printpath(path: List[int],list1) -> None:
	
	list1.append(path)

	#size = len(path)
	#for i in range(size):
		#print(path[i], end = " ")
		
	#print()

# Utility function to check if current
# vertex is already present in path
def isNotVisited(x: int, path: List[int]) -> int:

	size = len(path)
	for i in range(size):
		if (path[i] == x):
			return 0
			
	return 1

# Utility function for finding paths in graph
# from source to destination
def findpaths(g: List[List[int]], src: int,
			dst: int, v: int,list1) -> None:
				
	# Create a queue which stores
	# the paths
	q = deque()

	# Path vector to store the current path
	path = []
	path.append(src)
	q.append(path.copy())
	
	while q:
		path = q.popleft()
		last = path[len(path) - 1]

		# If last vertex is the desired destination
		# then print the path
		if (last == dst):
			printpath(path,list1)

		# Traverse to all the nodes connected to
		# current vertex and push new path to queue
		for i in range(len(g[last])):
			if (isNotVisited(g[last][i], path)):
				newpath = path.copy()
				newpath.append(g[last][i])
				q.append(newpath)

def get_key(val):
    for key, value in dict1.items():
         if val == value:
             return key


N = int(input())
ignore = [int(input()) for i in range(N)]
noe = int(input())
edges = [tuple(map(int,input().split())) for i in range(noe)]
destination = int(input())
source = int(input())

list1 = []
list2 = []
dict1 = {}
count = 0
for i in range(len(ignore)):
	if ignore[i] not in dict1:
		#print("ignore",ignore[i], count)
		dict1[ignore[i]] = count
		count = count + 1
		temp = count
	else:
		continue

# Number of vertices

g = [[] for _ in range(N)]

for i in range(len(edges)):
	p,q = edges[i]
	g[dict1[q]].append(dict1[p])

# Construct a graph


src = dict1[source]
dst = dict1[destination]
#print("path from src {} to dst {} are".format(
#	src, dst))

# Function for finding the paths
findpaths(g, src, dst, N,list1)

#print("list1",list1)
for i in range(len(list1)):
	val = list1[i]
	if val[1] not in list2:
		#print("val1",val[1])
		list2.append(get_key(val[1]))

se = list(set(list2))

for i in range(len(se)):
	print(se[i],end=" ")
# This code is contributed by sanjeev2552
