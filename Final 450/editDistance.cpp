// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int min_(int x, int y, int z){
        
        return min(x, min(y, z));
    }
    int editDistance(string s, string t) {
        // Code here
        int m = s.length(), n = t.length();
        int dp[2][m+1];
        
        memset(dp, 0, sizeof(dp));
        
        // if length(t) == 0, we have remove all chars of s
        for(int i = 0; i<=m; i++) dp[0][i] = i;
        
        for(int i=1; i<=n; i++){
            for(int j = 0; j<=m; j++){
                // if length(s) == 0, then we have to perform length(t) insert operations 
                if(j == 0) dp[i%2][j] = i;
                
                else if(s[j-1] == t[i-1]){
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                }
                
                else{
                    dp[i%2][j] = 1 + min_(dp[(i-1)%2][j], dp[i%2][j-1], dp[(i-1)%2][j-1]);
                }
                
            }
        }
        
        return dp[n%2][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends