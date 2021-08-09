// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends



int maxx(int a, int b, int c)
{
    return max(a, max(b, c));
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[n1 + 1][n2 + 1][n3 + 3];
    for(int i = 0; i<=n1; i++) for(int j = 0; j<=n2; j++) for(int k = 0; k<=n3; k++) dp[i][j][k] = 0;
    
    
    for(int i = 1; i<=n1; i++) 
        for(int j = 1; j<=n2; j++) 
            for(int k = 1; k<=n3; k++) 
                dp[i][j][k] = (A[i-1] == B[j-1] and B[j-1] == C[k-1]) ? 1 + dp[i-1][j-1][k-1] : maxx(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
    
    
    return dp[n1][n2][n3];    
}
