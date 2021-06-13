// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
    //code here
    int n = A.size();
    
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    
    dp[n] = 1;
    for(int i = n-1; i>=0; i--){
        for(auto w: B){
            if((i + w.size() <= n) and (A.substr(i, w.size()) == w)){
                dp[i] = dp[i + w.size()];
            }
            
            if (dp[i]) break;
        }
    }
    
    return dp[0];
    
    
}