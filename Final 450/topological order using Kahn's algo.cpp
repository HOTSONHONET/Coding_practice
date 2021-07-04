#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
// 	void topSortUtil(int n, vector<int> adj[], bool visited[], stack<int> &stk){
// 	    if(!visited[n]){
// 	        visited[n] = true;
// 	        for(auto i: adj[n])
// 	            topSortUtil(i, adj, visited, stk);
// 	    }
// 	    stk.push(n);
// 	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> in_degree(V, 0);
  
        // Traverse adjacency lists
        // to fill indegrees of
        // vertices.  This step
        // takes O(V+E) time
        for (int u = 0; u < V; u++) {
            vector<int>::iterator itr;
            for (itr = adj[u].begin();
                itr != adj[u].end(); itr++)
                in_degree[*itr]++;
        }
    
        // Create an queue and enqueue
        // all vertices with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (in_degree[i] == 0)
                q.push(i);
    
        // Initialize count of visited vertices
        int cnt = 0;
    
        // Create a vector to store
        // result (A topological
        // ordering of the vertices)
        vector<int> top_order;
    
        // One by one dequeue vertices
        // from queue and enqueue
        // adjacents if indegree of
        // adjacent becomes 0
        while (!q.empty()) {
            // Extract front of queue
            // (or perform dequeue)
            // and add it to topological order
            int u = q.front();
            q.pop();
            top_order.push_back(u);
    
            // Iterate through all its
            // neighbouring nodes
            // of dequeued node u and
            // decrease their in-degree
            // by 1
            vector<int>::iterator itr;
            for (itr = adj[u].begin();
                itr != adj[u].end(); itr++)
    
                // If in-degree becomes zero,
                // add it to queue
                if (--in_degree[*itr] == 0)
                    q.push(*itr);
    
            cnt++;
        }
    
        // Check if there was a cycle
        return (cnt != V) ? {} : top_order;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends