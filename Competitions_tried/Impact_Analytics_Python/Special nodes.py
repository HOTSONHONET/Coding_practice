"""

With this solution 100/100
testcases pass : 20/20

"""

from collections import deque


class Graph:

    def __init__(self, vertices):
        self.vertices = vertices
        self.adj = {i: [] for i in range(self.vertices)}

    def addEdge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def BFS(self, u):
        visited = [False for i in range(self.vertices + 1)]
        distance = [-1 for i in range(self.vertices + 1)]
        distance[u] = 0queue = deque()queue.append(u)
        visited[u] = True
        while queue:
            front = queue.popleft()
            for i in self.adj[front]:
                if not visited[i]:
                    visited[i] = True
                    distance[i] = distance[front] + 1
                    queue.append(i)
        maxDis = 0
        for i in range(self.vertices):
            if(distance[i] > maxDis):
                maxDis = distance[i]
                nodeIdx = i
                nodes = []

        for i in range(self.vertices):
            if(distance[i] == maxDis):
                nodes.append(i)
        # print(nodes)
        # # print("====")
        return nodeIdx, maxDis, nodes

        def longestPathLengthNodes(self):
            ans = [0]*self.vertices
            node, dis, nodes_0 = self.BFS(0)
            for i in nodes_0:
                ans[i] = 1
            node_2, LongDis, node_n = self.BFS(node)
            for i in node_n:
                ans[i] = 1return ans


N = int(input())
G = Graph(N)
# print(N)
for i in range(N-1):
    a, b = tuple(map(int, input().split()))
    # print(a, b)
    G.addEdge(a-1, b-1)

ans = G.longestPathLengthNodes()
ans = list(map(str, ans))
print(" ".join(ans))
