#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ipair pair<int,int>

int f(int n){
    return (n==0 || n==1) ? 1 : n*f(n-1);
}

int main(){
    
    string s;
    cin>>s;
    map<char, int> m;
    for(auto i: s) m[i]++;
    
    
    int n = f(s.size());
    for(auto i:m){
        if(i.second>1) n/=f(i.second);   
    }
    cout<<n<<endl;
    vector<string> v;
    while(n--){
        v.push_back(s);
        next_permutation(s.begin(), s.end());
    }
    
    sort(v.begin(), v.end());        
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    return 0;
}