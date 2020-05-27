import numpy
import time
import sys
start = time.process_time()
def BellmanFord(graph, V, E, src):
    dist = [sys.maxsize] * V
    dist[src] = 0

    for i in range(V - 1):
        for j in range(E) :
            if dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]] :
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2]
                
    for i in range(E) :
        source = graph[i][0]
        dest = graph[i][1]
        weight = graph[i][2]
        if dist[source] != sys.maxsize and dist[source] + weight < dist[dest] :
            print("Graph contains negative weighted cycle")
            
    print("Vertex\tSource")
    for i in range(V) :
         print("Vertex {} :-> cost = {}".format(i, dist[i]))
        
V = int(input("Enter the number of vertices : "))
E = int(input("Enter the numberof edges: "))
assert V > 0, "The number of vertices should be more than zero"
assert E > 0, "The number of edges should be more than zero"
print("Please enter the source, destination and weight of every edge in matrix form")
elements = list(map(int,input().split()))
matrix = numpy.array(elements).reshape(E,3)
print("The rows represent each edge, and the columns are the attributes of edge")
print("The given matrix is : ")
print(matrix)
graph = matrix
print("Please enter the source vertex ")
source = int(input())
BellmanFord(graph, V, E, source)
end = time.process_time()
print("Time elapsed during execution : {}".format(end-start))
