// A snake is coiled in the form of a rectangular matrix. You are given that snake's coiling starting position and the direction of its coiling.
// Coiling is spiral in nature and will move inwards. Each cell is either venomous or non venomous. Venomous cell is represented with -1 and the non venomous with 1.
// Your task is to find the longest edible(non venomous) part of that snake in uncoiled position.

// Coiling start representation:
// 0 - start is (0,0)
// 1 - start is (0,m-1)
// 2 - start is (n-1,m-1)
// 3 - start is (n-1, 0)
// where n - number of rows of a matrix, m - number of columns of a matrix

// Coiling direction representation:
// 0 - clockwise coiling
// 1 - anticlockwise coiling

#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int k = 0, l = 0;
        while(k<r && l<c){
            
            for(int i = l; i<c; i++){
                ans.push_back(matrix[k][i]);
            }
            k++;
            
            for(int i = k; i<r; i++){
                ans.push_back(matrix[i][c-1]);
            }
            c--;
            
            if(k<r){
                for(int i  = c-1; i>=l; --i){
                    ans.push_back(matrix[r-1][i]);
                }
                r--;
            }
            
            if(l<c){
                for(int i = r-1; i>=k; --i){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }


int edibleSlice(int n, int m, vector<vector<int>> mat, int coil_starting, int coil_direction ){
    vector<int> vec = spirallyTraverse(mat, n, m);
    int max_ones = 0, count = 0;
    for(auto i: vec){
        if(i == -1){
            max_ones = max(max_ones, count);
            count = 0;
        }
        else{
            count++;
        }
    }
    return max_ones;
}


int main(){
    int n, m, coil_starting, coil_direction;
    cin>> n >> m >> coil_starting >> coil_direction;
    vector<vector<int > > matrix(n, vector<int>(m));
    for(int i=0; i< n;i++){
        for(int j=0 ;j<m;j++){
            cin>> matrix[i][j];
        }
    }
    int result = edibleSlice(n, m, matrix, coil_starting, coil_direction);
    cout<< result<<"\n";
}