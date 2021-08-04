// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

 

#define mod 1000000007
#define ll long long

class Solution{
    public:
    ll countWays(int n, int k){
        // code here
        ll dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[1] = k; dp[2] = k*k;
        
        for(int i = 3; i<=n; i++)
        {
            dp[i] = ((k-1)*(dp[i-1] + dp[i-2]))%mod;
        }
        
        return dp[n];
        
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends