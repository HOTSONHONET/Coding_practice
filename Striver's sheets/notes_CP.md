# CP sheet solution [👩🏼‍💻](https://docs.google.com/document/d/1vShwt8yXYUOgkF53-iYAuJXWR7Yi5VSJrW2xB49o0PM/edit)

### Linear Search

1. Maximum Sum

```

/*

T(N) = O(N)
O(N) = O(1)

*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0; i<n; i++){
      cin>>v[i];
    }

    ll maxx = *max_element(v.begin(), v.end());
    if(maxx < 0){
      cout<<(*max_element(v.begin(), v.end()))<<" "<<1<<"\n";
      return;
    }

    int cnt = 0;
    ll sum = 0;
    for(int i = 0; i<n; i++){
      if(v[i] >=0){
        cnt++, sum += (ll)v[i];
      }
    }

    cout<<sum<<" "<<cnt<<"\n";

}


int main()
{
    solve();
    return 0;
}

```
