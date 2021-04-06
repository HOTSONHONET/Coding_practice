// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void print(vector<int> v){
        for (auto i: v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
	vector<int>bfsOfGraph(int n, vector<int> adj[]){
	    // Code here
	    vector<int> ans, distance(n);
	    vector<bool> visited(n);
	    fill(visited.begin(), visited.end(), false);
	    
	    
	    queue<int> q;
	    
	    visited[0] = true;
	    ans.push_back(0);
	    distance[0] = 0;
	    q.push(0);
	   // print(ans);
	    
	    while(!q.empty()){
	        int s = q.front();
	        q.pop();

	        for(auto u: adj[s]){
	            if(visited[u] == true) continue;
	            
	            else{
	                visited[u] = true;
	                ans.push_back(u);
	                distance[u] = distance[s] + 1;
	                q.push(u);
	            }
	        }
	    }
	    
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends