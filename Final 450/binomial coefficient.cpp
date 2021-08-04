// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

const int p = 1000000007;
class Solution{
    public:
    
    int nCr(int n, int r){
        if(n<r) return 0;
        if(r > n - r) r = n - r;
        int C[r+1];
        memset(C, 0, sizeof(C));
        
        C[0] = 1;
        for(int i = 1; i<=n; i++)
        {
            for(int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j-1])%p;
        }
        
        return C[r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends