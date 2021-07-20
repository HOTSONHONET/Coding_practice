class Solution {
public:
    void dfs(int x, int y, int r, int c, int cur_color, vector<vector<int>> image, vector<vector<int>> &visited)
    {   
        if(x<0 || y<0 || x>=r || y>=c || visited[x][y]) return;
        
        if(image[x][y] == cur_color)
        {
            visited[x][y] = 1;
            dfs(x-1, y, r, c, cur_color, image, visited);
            dfs(x, y-1, r, c, cur_color, image, visited);
            dfs(x, y+1, r, c, cur_color, image, visited);
            dfs(x+1, y, r, c, cur_color, image, visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size(), c = image[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));
        
        dfs(sr, sc, r, c, image[sr][sc], image, visited);
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(visited[i][j]) image[i][j] = newColor;
            }
        }
        
        return image;
    }
};