// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;

#define R 12
#define C 10

struct Key{
	int x,y;
	Key(int i,int j){ x=i;y=j;};
};

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

// A function to check if a given cell (x, y) is
// a valid cell or not
bool isValid(int x, int y)
{
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;

	return false;
}

// A function to mark all adjacent cells of
// landmines as unsafe. Landmines are shown with
// number 0
void findShortestPath(int mat[R][C]){
	int i,j;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			// if a landmines is found
			if (mat[i][j] == 0)
			{
			// mark all adjacent cells
			for (int k = 0; k < 4; k++)
				if (isValid(i + rowNum[k], j + colNum[k]))
					mat[i + rowNum[k]][j + colNum[k]] = -1;
			}
		}
	}
// mark all found adjacent cells as unsafe
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (mat[i][j] == -1)
				mat[i][j] = 0;
		}
	}

	int dist[R][C];

	for(i=0;i<R;i++){
		for(j=0;j<C;j++)
			dist[i][j] = -1;
	}
	queue<Key> q;

	for(i=0;i<R;i++){
		if(mat[i][0] == 1){
			q.push(Key(i,0));
			dist[i][0] = 0;
		}
	}

	while(!q.empty()){
		Key k = q.front();
		q.pop();

		int d = dist[k.x][k.y];

		int x = k.x;
		int y = k.y;

		for (int k = 0; k < 4; k++) {
			int xp = x + rowNum[k];
			int yp = y + colNum[k];
			if(isValid(xp,yp) && dist[xp][yp] == -1 && mat[xp][yp] == 1){
				dist[xp][yp] = d+1;
				q.push(Key(xp,yp));
			}
		}
	}
	// stores minimum cost of shortest path so far
	int ans = INT_MAX;
	// start from first column and take minimum
	for(i=0;i<R;i++){
		if(mat[i][C-1] == 1 && dist[i][C-1] != -1){
			ans = min(ans,dist[i][C-1]);
		}
	}
	
	// if destination can be reached
	if(ans == INT_MAX)
		cout << "NOT POSSIBLE\n";
		
	else// if the destination is not reachable
		cout << "Length of shortest safe route is " << ans << endl;
}

// Driver code
int main(){
	
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};
	
	// find shortest path
	findShortestPath(mat);
}
