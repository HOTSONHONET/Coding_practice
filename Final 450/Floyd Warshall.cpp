// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

#define INF 999

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int v = matrix.size();
	    int dist[v][v], i, j, k;
	    for(i = 0; i<v; ++i)
	        for(j = 0; j<v; ++j)
	            dist[i][j] = matrix[i][j];
        for(k = 0; k<v; k++){
            for(i = 0; i<v; i++){
                for(j = 0; j<v; j++){
                    if(dist[i][j] > (dist[i][k] + dist[k][j])
                        && dist[i][k] != -1
                        && dist[k][j] != -1
                        && dist[i][j] != -1
                    ){
                        // cout<<dist[i][j]<<" "<<dist[i][k]<<" "<<dist[k][j]<<endl;
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    
                    if(dist[i][k] != -1 && dist[k][j] != -1){
                        dist[i][j] =  (dist[i][j] >= 0) ? min(dist[i][j], dist[i][k] + dist[k][j]): dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        
        for(i = 0; i<v; ++i){
	        for(j = 0; j<v; ++j) matrix[i][j] = dist[i][j];
	    }        
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends