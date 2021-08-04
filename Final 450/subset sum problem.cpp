// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i<n; i++) sum += arr[i];
        
        if(sum%2) return 0;
        
        int req_sum = sum /2;
        
        bool dp[req_sum + 1];
        memset(dp, false, sizeof(dp));
        
        
        for(int i = 0; i<n; i++)
            for(int j = req_sum; j>=arr[i]; j--)
            {   
                
                if (dp[j - arr[i]] || j == arr[i])  dp[j] = true;
            }
        
        // for(int i = 0; i<req_sum + 1; i++) cout<<i<<"--->"<<dp[i]<<endl;
        return dp[req_sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends