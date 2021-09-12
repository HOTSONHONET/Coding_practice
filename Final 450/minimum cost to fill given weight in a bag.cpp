// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:

	int minimumCost(int arr[], int N, int W) 
	{ 
        int dp[N+1][W+1];
        
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                if(j==0) dp[i][j] = 0;
                
                else if(i==0) dp[i][j] = INT_MAX-1;
                
                else if(j-i >= 0 and arr[i-1]!=-1 and dp[i][j-i]!=INT_MAX-1) {
                    dp[i][j]=min( arr[i-1] + dp[i][j-i] , dp[i-1][j]);
                }
                
                else dp[i][j] = dp[i-1][j];
            }
        }
       
        return dp[N][W]==INT_MAX-1 ? -1 : dp[N][W];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends