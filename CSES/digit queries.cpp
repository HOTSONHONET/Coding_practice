#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ipair pair<int,int>


int main(){
    
    int q;
    cin>>q;
    vector<ll> v;
    while(q--){
        ll tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    
    ll mi = *max_element(v.begin(), v.end());
    ll i = 1;
    string s = "";
    while(mi--){
        s += to_string(i);
        i++;
    }
    
    // cout<<s<<endl;
    for(auto i: v){
        cout<<s[i-1]<<endl;
    }
    return 0;
}