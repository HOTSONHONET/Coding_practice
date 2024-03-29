// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int R, C;
    bool isvalid(int i, int j)
    {
        return (i >= 0 && j >= 0 && i < R && j < C);
    }
     
    // structure for storing coordinates of the cell
    struct ele {
        int x, y;
    };
     
    // Function to check whether the cell is delimiter
    // which is (-1, -1)
    bool isdelim(ele temp)
    {
        return (temp.x == -1 && temp.y == -1);
    }
     
    // Function to check whether there is still a fresh
    // orange remaining
    bool checkall(vector<vector<int>>& arr)
    {
        for (int i=0; i<R; i++)
           for (int j=0; j<C; j++)
              if (arr[i][j] == 1)
                 return true;
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& arr) {
        // Code here
        // Create a queue of cells
        R = arr.size();
        C = arr[0].size();
        queue<ele> Q;
        ele temp;
        int ans = 0;
     
        // Store all the cells having rotten orange in first time frame
        for (int i=0; i<R; i++)
        {
           for (int j=0; j<C; j++)
           {
                if (arr[i][j] == 2)
                {
                    temp.x = i;
                    temp.y = j;
                    Q.push(temp);
                }
            }
        }
     
        // Separate these rotten oranges from the oranges which will rotten
        // due the oranges in first time frame using delimiter which is (-1, -1)
        temp.x = -1;
        temp.y = -1;
        Q.push(temp);
     
        // Process the grid while there are rotten oranges in the Queue
        while (!Q.empty())
        {
            // This flag is used to determine whether even a single fresh
            // orange gets rotten due to rotten oranges in current time
            // frame so we can increase the count of the required time.
            bool flag = false;
     
            // Process all the rotten oranges in current time frame.
            while (!isdelim(Q.front()))
            {
                temp = Q.front();
     
                // Check right adjacent cell that if it can be rotten
                if (isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 1)
                {
                    // if this is the first orange to get rotten, increase
                    // count and set the flag.
                    if (!flag) ans++, flag = true;
     
                    // Make the orange rotten
                    arr[temp.x+1][temp.y] = 2;
     
                    // push the adjacent orange to Queue
                    temp.x++;
                    Q.push(temp);
     
                    temp.x--; // Move back to current cell
                }
     
                // Check left adjacent cell that if it can be rotten
                if (isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.x-1][temp.y] = 2;
                    temp.x--;
                    Q.push(temp); // push this cell to Queue
                    temp.x++;
                }
     
                // Check top adjacent cell that if it can be rotten
                if (isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.x][temp.y+1] = 2;
                    temp.y++;
                    Q.push(temp); // Push this cell to Queue
                    temp.y--;
                }
     
                // Check bottom adjacent cell if it can be rotten
                if (isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.x][temp.y-1] = 2;
                    temp.y--;
                    Q.push(temp); // push this cell to Queue
                }
     
                Q.pop();
            }
     
            // Pop the delimiter
            Q.pop();
     
            // If oranges were rotten in current frame than separate the
            // rotten oranges using delimiter for the next frame for processing.
            if (!Q.empty()) {
                temp.x = -1;
                temp.y = -1;
                Q.push(temp);
            }
     
            // If Queue was empty than no rotten oranges left to process so exit
        }
     
        // Return -1 if all arranges could not rot, otherwise return ans.
        return (checkall(arr))? -1: ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends