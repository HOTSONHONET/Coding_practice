// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char, int> m;
        for(char a: s) m[a]++;
        
        priority_queue<int> pq;
        for(auto i: m) pq.push(i.second);
        
        while(k !=0){
            int tmp = pq.top();
            pq.pop();
            --tmp;
            pq.push(tmp);
            k--;
        }
        
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top()*pq.top();
            pq.pop();
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends