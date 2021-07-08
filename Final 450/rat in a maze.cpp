// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

#define max_size 5


class Solution{
    public:
    
    
    bool isSafe(int row, int col, vector<vector<int>> m, int n, bool visited[][max_size]){
        return (row == -1 || col == -1 || row == n || col == n || visited[row][col] || m[row][col] == 0) ? false : true;
    }
    
    void pathUtils(int row, int col, vector<vector<int>> m, int n, string &path, vector<string> &possiblePaths, bool visited[][max_size])
    {
        if (row == -1 || col == -1 || row == n || col == n || visited[row][col] || !m[row][col]) return;
        
        if (row == n-1 && col == n-1)
        {
            possiblePaths.push_back(path);
            return;
        }
        
        visited[row][col] = true;
        
        // Down move
        if(isSafe(row+1, col, m, n, visited))
        {
            path.push_back('D');
            pathUtils(row+1, col, m, n, path, possiblePaths, visited);
            path.pop_back();
        }
        
        // Left move
        if(isSafe(row, col-1, m, n, visited))
        {
            path.push_back('L');
            pathUtils(row, col-1, m, n, path, possiblePaths, visited);
            path.pop_back();
        }
        
        // Right move
        if(isSafe(row, col+1, m, n, visited))
        {
            path.push_back('R');
            pathUtils(row, col+1, m, n, path, possiblePaths, visited);
            path.pop_back();
        }
        
        // Up move
        if(isSafe(row-1, col, m, n, visited))
        {
            path.push_back('U');
            pathUtils(row-1, col, m, n, path, possiblePaths, visited);
            path.pop_back();
        }
        
        visited[row][col] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string path;
        vector<string> possiblePaths;
        bool visited[n][max_size];
        memset(visited, false, sizeof(visited));
        pathUtils(0, 0, m, n, path, possiblePaths, visited);
        
        return possiblePaths;
        
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends