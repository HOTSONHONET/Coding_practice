class Solution {
public:
    
    map<int, bool> visited;
    int uselessCables = 0;
    
    void dfs(int s, map<int, vector<int>>&adj)
    {
        if (visited[s]){
            uselessCables++;
            return;
        }
        
        else{
            visited[s] = true;
            for(auto u: adj[s]) dfs(u, adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int disConnects = 0;
        uselessCables = 0;
        
        map<int, vector<int>> adj;
        
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }    
        
        // Performing complete DFS
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj);
                disConnects++;
            }
        }
        
        // rightNow it contains all the connected components
        // With "C" connected components, we will have "C-1" disconnects
        disConnects--;
        
        // Because it is also considering those nodes which are proper connections
        uselessCables -= connections.size();
        
        cout<<uselessCables <<" "<< disConnects<<endl;
        return (uselessCables < disConnects) ? -1 : disConnects;
        
    }
};