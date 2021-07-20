#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ipair pair<int,int>


int main(){
    
    int n;
    cin>>n;
    for(int i = 0; i<(1<<n); i++)
    {
        int val = (i^(i>>1));
        bitset<32> r(val);
        string tmp = r.to_string();
        cout<<tmp.substr(32-n)<<endl;
    }
    return 0;
}