#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ipair pair<int,int>

ll solve(vector<int> v, int n)
{
    
    ll ans = 0;
    ll sum = 0;
    for(int i: v) sum+=i;
    for(int i = 0; i<(1<<n); i++){
        ll tmp = 0;
        for(int j = 0; j<n; j++)
        {
            if(i&(1<<j)) tmp += v[j];
        }
        
        ans = max(ans, (tmp <= sum/2) ? tmp : 0);
    }
    
   
    
    return sum - 2*ans;
}

int main(){
    
    int n;
    cin>>n;
    vector<int> v;
    
    while(n--){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);    
    }
    
    cout<<solve(v, v.size())<<endl;
    return 0;
}