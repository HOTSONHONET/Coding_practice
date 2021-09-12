// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr(string X, string Y, int n, int m)
    {
        // your code here
        vector<vector<int>> LCSuff(n+1, vector<int>(m+1, 0));
        int result = 0; 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (i == 0 || j == 0)
                    LCSuff[i][j] = 0;
     
                else if (X[i - 1] == Y[j - 1]) {
                    LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                    result = max(result, LCSuff[i][j]);
                }
                else
                    LCSuff[i][j] = 0;
            }
        }
        return result;  
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends