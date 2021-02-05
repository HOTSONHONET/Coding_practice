#include<bits/stdc++.h>

using namespace std;

# define MAX 100



// In this function, we will make matrix which will store every max value possible for every path from right to left
// At last we will search for the max value in the 1st column 

int solve(int goldMine[][MAX], int rows, int cols){
    int goldMangta[rows][cols];
    memset(goldMangta, 0, sizeof(goldMangta));

    for(int col = cols-1; col>=0; col--){
        for(int row = 0; row<rows; row++){
            int right = (col == cols-1) ? 0 : goldMangta[row][col+1];
            int rightUp = (col == cols-1 || row == 0) ? 0 : goldMangta[row-1][col+1];
            int rightDown = (col == cols-1 || row == m-1) ? 0 : goldMangta[row+1][col+1];

            goldMangta[row][col] = goldMine[row][col] + max(right, max(rightUp, rightDown));
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, goldMangta[i][0]);
    }
    return ans;

}


int main(){
    int t;
    cin>>t;
    for(int tt = 0; tt<t; tt++){
        int rows, cols;
        cin>>rows>>cols;
        int goldMine[rows][cols];
        for(int row = 0; rows < rows; row++){
            for(int col = 0; col<cols; col++){
                cin>>goldMine[row][col];
            }
        }
        cout<<solve(goldMine, rows, cols)<<endl;

    }
    return 0;
}
