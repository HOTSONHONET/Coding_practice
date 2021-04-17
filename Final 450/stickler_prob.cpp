// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    
    ll FindMaxSum(ll arr[], ll n)
    {
       if (n==1) return arr[0];
       if (n==2) return max(arr[0], arr[1]);
       
       ll ans, v1 = arr[0], v2 = max(arr[0], arr[1]);
       for(int i = 2; i<n; i++)
       {
           ans = max(v1 + arr[i], v2);
           v1 = v2;
           v2 = ans;
       }
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends