// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[202][202][2];
Solution(){
    memset(dp,-1,sizeof(dp));
}
    int p(string &s,int n,int i,int j,bool x){
        if(dp[i][j][x]!=-1)return dp[i][j][x]%1003;
        int res=INT_MIN;
        if(i>j)return 0;
        if(i==j){
            if(x){
                return res=s[i]=='T';
            }
            else
                return res=s[i]=='F';
        }
        int temp=0;
        for(int k=i+1;k<j;k+=2){
            int lf,rf,lt,rt;
            lt=p(s,n,i,k-1,true);
            lf=p(s,n,i,k-1,false);
            rt=p(s,n,k+1,j,true);
            rf=p(s,n,k+1,j,false);
            if(s[k]=='|'){
                if(x)
                temp+=lf*rt+lt*rf+lt*rt;
                else
                temp+=lf*rf;
            }
            if(s[k]=='&'){
                if(x)
                temp+=lt*rt;
                else
                temp+=lf*rf+lf*rt+lt*rf;
            }
            if(s[k]=='^'){
                if(x)
                temp+=lf*rt+lt*rf;
                else
                temp+=lf*rf+lt*rt;
            }
            
        }
        res=(res==INT_MIN)?temp:res;
        dp[i][j][x]=res%1003;
        return dp[i][j][x]%1003;
    }
    int countWays(int n, string s){
        int x=p(s,n,0,n-1,true);
        return x;
    }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends