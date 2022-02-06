#include<bits/stdc++.h>

using namespace std;

#define MAX 1000000007 
#define ipair pair<int, int> 
#define ll long long int


void allSubsets(vector<ll> v, ll n, ll r, ll index, vector<ll> d, ll i, vector<vector<ll>> &result)
{
    if(index == r){
        for(ll j = 0; j<r; j++)
        {
            result.push_back(d);
        }
        
        return;
    }
    
    if(i>=n) return;
    
    d[index] = v[i];
    allSubsets(v, n, r, index+1, d, i+1, result);
    allSubsets(v, n, r, index, d, i+1, result);
    
}

ll fact(ll n){
    return (n==0||n==1) ? 1 : n*fact(n-1);
}

ll solve(ll t, ll m, vector<ll> v)
{   
    ll n = v.size();
    ll ans = 0;
    
    vector<ll> data(m);
    vector<vector<ll>> results;
    
    allSubsets(v, n, m, 0, data, 0, results);
    
    ll factN = fact(n);
    unordered_set<string> visited;
    
    for(auto vs:  results){
        sort(vs.begin(), vs.end());
        string tmp = "";
        for(auto i: vs){
            tmp += to_string(i);
        }
        if(visited.find(tmp) == visited.end())
        {   
            visited.insert(tmp);
            ll sum_ = 0;
            set<ll> st;
            
            for(auto i: vs){
                sum_+=i;
                st.insert(i);
            }
            if(sum_ == t) ans += (fact(st.size())%MAX);
        }
    }
    return ans%MAX;
}

int main(){
    
    ll n, m;
    cin>>n>>m;
    set<ll> s;
    vector<ll> v;
    ll start = 0;
    ll tmpM = m;
    while(tmpM--)
    {
        ll a, b;
        cin>>a>>b;
        for(ll i = a; i<=b; ++i)
        {
            // s.insert(i);
            v.push_back(i);
            
        }
        
    }
    
    // for(auto i: v){
    //     // v.push_back(i);
    //     cout<<i<<" ";
    // }
    
    // cout<<endl;

    cout<<solve(n, m, v)<<endl;
    
    return 0;
}