// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	map<int, bool> visited;
	vector<int> rAdj[5001];
	
	
	void dfs(int v, vector<int> adj[]){
	    visited[v] = true;
	    
	    for(auto i: adj[v]){
	        if(!visited[i]) dfs(i, adj);
	    }
	}
	
	
	void getTranspose(vector<int> adj[], int V){
        for(int v = 0; v<V; v++){
            for(auto i: adj[v]){
                rAdj[i].push_back(v);
            }
        }
	}
	
	void fillOrder(int v, vector<int> adj[], map<int, bool> &visited, stack<int> &stk){
	    visited[v] = true;
	    for(auto i: adj[v]){
	        if(!visited[i]) fillOrder(i, adj, visited, stk);
	    }
	    
	    stk.push(v);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> stk;
        
        for(int i = 0; i<V; i++) visited[i] = false;
        for(int i = 0; i<V; i++){
            if(visited[i] == false) fillOrder(i, adj, visited, stk);
        }
        
        getTranspose(adj, V);
        
        for(int i = 0; i<V; i++) visited[i] = false;
        int ans = 0;
        while(!stk.empty())
        {
            int v = stk.top();
            stk.pop();
            
            if(!visited[v]){
                dfs(v, rAdj);
                ans++;
            }
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends