#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ipair pair<int,int>


void solve(int n, int from, int to, int aux, vector<ipair> &v)
{   

    /*
    The pattern here is :
    Shift 'n-1' disks from 'A' to 'B'.
    Shift last disk from 'A' to 'C'.
    Shift 'n-1' disks from 'B' to 'C'.
    
    */
    if(n==1){
        v.push_back({from, to});
        return;
    }
    solve(n-1, from, aux, to, v);
    v.push_back({from, to});
    solve(n-1, aux, to, from, v);
}

int main(){
    
    int n;
    cin>>n;
    vector<ipair> v;
    solve(n, 1, 3, 2, v);
    cout<<v.size()<<endl;
    for(auto i: v){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}