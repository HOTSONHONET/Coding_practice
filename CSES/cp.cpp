#include<bits/stdc++.h>

using namespace std;

#define ll long long




int main(){
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++){
        int l, r;
        cin>>l>>r;

        cout<<(((l+r)%3 == 0) && (2*l >=r) && (2*r>=l) ? "YES" : "NO")<<endl;
    }

    return 0;


}