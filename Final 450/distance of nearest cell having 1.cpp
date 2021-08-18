// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
public:
    bool isSafe(int x,int y,int r,int c)
    {
        if(x>=0&&x<r&&y>=0&&y<c)
            return true;
        return false;
    }
	vector<vector<int>> nearest(vector<vector<int>>grid){
	    // Code here
	   int r=grid.size();
	   int c=grid[0].size();
	   vector<vector<int>> ans(r);
	   for(int i=0;i<r;i++)
	   {
	       for(int j=0;j<c;j++)
	       {
	           ans[i].push_back(INT_MAX);
	       }
	   }
	   queue<pair<int,int>> q;
	   vector<pair<int,int>> dirs={{0,-1},{0,1},{-1,0},{1,0}};
	   for(int i=0;i<r;i++)
	   {
	       for(int j=0;j<c;j++)
	       {
	           if(grid[i][j]==1)
	           {
	               ans[i][j]=0;
	               q.push({i,j});
	           }
	       }
	   }
	   while(!q.empty())
	   {
	       pair<int,int> tmp=q.front();
	       q.pop();
	       int x=tmp.first; int y=tmp.second;
	       for(auto d:dirs)
	       {
	            int newX=x+d.first;
	            int newY=y+d.second;
	            if(isSafe(newX,newY,r,c)&&ans[newX][newY]>ans[x][y]+1)
	            {
	                ans[newX][newY]=ans[x][y]+1;
	                q.push({newX,newY});
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends