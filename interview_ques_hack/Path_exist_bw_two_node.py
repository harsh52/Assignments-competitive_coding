'''
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
from collections import deque
class Graph:
    def __init__(self,edges,N):
        self.adjList = [[] for _ in range(N)]
        for (src,dest) in edges:
            self.adjList[src].append(dest)
           
def isconnected(graph,src,dest, discovered):
    q = deque()
    discovered[src] = True
    q.append(src)
    while(q != None):
        v = q.popleft()
        if(v == dest):
            return True
        for u in graph.adjList[v]:
            if not discovered[u]:
                discovered[u] = True
                q.append(u)
    return False
   
N = int(input())
ignore = [int(input()) for i in range(N)]
noe = int(input())
edges = [tuple(map(int,input().split())) for i in range(noe)]
source = int(input())
destination = int(input())

'''
print(N)
print(edges)
print(source)
print(destination)
print("max",max(max(edges)))
'''
#print(ignore)
count = 0
dict1 = {}
edges2 = []
for i in range(len(ignore)):
    dict1[ignore[i]] = count
    count = count + 1
   
for i in range(len(edges)):
    n,k = edges[i]
    p = dict1[n]
    q = dict1[k]
    edges2.append((p,q))

#print(edges2)
source = dict1[source]
destination = dict1[destination]
graph = Graph(edges2,N)
discovered = [False] * N
(src, dest) = (source,destination)
if(isconnected(graph,src,dest,discovered)):
    print("TRUE")
else:
    print("False")