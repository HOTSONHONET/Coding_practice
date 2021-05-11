// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int results[n+1][k+1];
        int i, j, res;
        
        for(i = 0; i<=n; i++){
            results[i][1] = 1;
            results[i][0] = 0;
        }
        
        for(j = 0; j<=k; j++){
            results[1][j] = j;
        }
        
        
        for(i = 2; i<=n; i++){
            for(j = 2; j<=k; j++){
                results[i][j] = INT_MAX;
                for(int x = 1; x<=j; x++){
                    res = max(results[i-1][x-1], results[i][j-x]) + 1;
                    
                    results[i][j] = min(results[i][j], res);
                }
            }
        }
        
        return results[n][k];
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends