// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


#define mod 1000000007

class Solution
{
public:

    int countFriendsPairings(int n) 
    { 
        // code here
        long long a = 1, b = 2, c = 0;
        if(n <=2 ) return n;
        for(int i = 0; i<=n; i++)
        {
            c = b + (((i - 1)*a) % mod);
            a = b;
            b = c;
        }
        
        // cout<<c<<endl;
        return c%mod;
        
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends