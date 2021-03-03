#include <bits/stdc++.h>

using namespace std;

#define ll long long


ll solve(string n, vector<string> dict){
    ll ans = 0, i = 0;
    while(i < dict.size()){
        for(auto w: dict){
            ll j = 0;
            string curpart = n;

            if(w.length() < curpart.length() && w == curpart.substr(j, w.length())){
                curpart = curpart.substr(j, w.length());
                ans ++;
                j += w.length();
            }

        }
        i++;
    }

    return ans%((int) 1e9 + 7);
}

int main(){
    string word;
    vector<string> dict;
    cin>>word;
    int n;
    cin>>n;

    for (int i = 0; i<n; i++){
        string tmp;
        cin>>tmp;
        dict.push_back(tmp);
    }

    cout<<solve(word, dict);

    return 0;
}