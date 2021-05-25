// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int mini;
    int dfs(int start[], int dia[], int x){
        if(dia[x] < mini and dia[x]!=0){
            mini = dia[x];
        }    
        if(start[x] == 0) return x;
        return dfs(start, dia, start[x]);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<vector<int>> ans;
        int start[n+1], end[n+1], dia[n+1];
        memset(start, 0, sizeof(start));
        memset(end, 0, sizeof(end));
        memset(dia, 0, sizeof(dia));
        
        for(int i = 0; i<p; i++){
            start[a[i]] = b[i];
            end[b[i]] = a[i];
            dia[a[i]] = d[i];
        }
        
        for(int i = 1; i<=n; i++){
            if(start[i]!=0 and end[i]==0){
                mini = INT_MAX;
                int end = dfs(start, dia, i);
                ans.push_back({i, end, mini});
            }
        }
        
        return ans;
        
        
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends