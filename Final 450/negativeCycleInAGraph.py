#User function Template for python3

class Solution:
	def isNegativeWeightCycle(self, n, edges):
		#Code here
		dist = [float("Inf")] * n 
        dist[0] = 0
        
        for _ in range(n-1): 
            for edge in edges: 
                u, v, w = edge
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w 
  
        for edge in edges: 
            u, v, w = edge
            if dist[u] != float("Inf") and dist[u] + w < dist[v]: 
                return 1
        
        return 0

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n, m = input().split()
		n = int(n)
		m = int(m)
		edges = []
		for _ in range(m):
			edges.append(list(map(int, input().split())))
		obj = Solution()
		ans = obj.isNegativeWeightCycle(n, edges)
		print(ans)

# } Driver Code Ends