// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    //Function to find the number of islands.
    int isSafe(vector<vector<char>> &M, int row, int col, vector<vector<int>> &visited)
    {
        // row number is in range, column
        // number is in range and value is 1
        // and not yet visited
        int ROW = M.size(), COL = M[0].size();
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col]=='1' && !visited[row][col]);
    }
    void DFS(vector<vector<char>> &M, int row, int col, vector<vector<int>> &visited)
    {   
        static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
     
        // Mark this cell as visited
        visited[row][col] = true;
     
        // Recur for all connected neighbours
        for (int k = 0; k < 8; ++k)
            if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
                DFS(M, row + rowNbr[k], col + colNbr[k], visited);
         
    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> visited(r, vector<int>(c,false));
        
        int cnt = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j =0; j<c; ++j)
            {
                if(grid[i][j] == '1' and !visited[i][j])
                {
                    DFS(grid, i, j, visited);
                    ++cnt;
                }
            }
        }
        
        
        return cnt;

        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends