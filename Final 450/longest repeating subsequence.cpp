// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	   // vector<vector<int>> dp(1001, vector<int>(1001, 0));
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
		    for(int i = 1; i<=n; i++)
                for(int j = 1; j<=n; j++)
                   dp[i][j] = (str[i - 1] == str[j - 1] and i!=j) ? 1 + dp[i-1][j-1] : max(dp[i][j-1], dp[i-1][j]);
		
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends