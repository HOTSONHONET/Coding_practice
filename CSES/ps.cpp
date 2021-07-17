#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ipair pair<int,int>

string solve(string s, map<char, int> m){
    string evenS = "";
    string oddS = "";
    for(auto i: m){
        if(i.second%2==0){
            int tmp = i.second/2;
            while(tmp--){
                evenS+=i.first;
            }
        }
        else{
            int tmp = i.second;
            while(tmp--) oddS+=i.first;
        }
    }
    
    string rev = evenS;
    reverse(rev.begin(), rev.end());
    string finalANS = evenS + oddS + rev;
    return finalANS;
}


int main(){
    
    string s;
    cin>>s;
    
    if(s.size() == 1) cout<<s<<endl;
    else{
        map<char, int> m;
        for(auto i: s) m[i]++;
        int evenCnt = 0, oddCnt = 0;
        for(auto i: m)
        {
            if(i.second%2==0) evenCnt++;
            else oddCnt++;
        }
        
        if(oddCnt > 1) cout<<"NO SOLUTION"<<endl;
        
        else{
            cout<<solve(s, m)<<endl;
        }
        
    }
    
    return 0;
}