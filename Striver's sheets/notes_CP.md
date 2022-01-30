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

2. Bear and Segment

```

/*
T(N) = O(N)
S(N) = O(1)
*/

#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    
    int n = s.size(), one_count = 0;
    for(int i = 0; i<n; ){
        if(s[i] == '1'){
            one_count++;
            while(s[i++] == '1');
        }else{
            i++;
        }
    }
    
    cout<<((one_count == 1) ? "YES" : "NO")<<endl; 
}


int main()
{
    int tcs;
    cin>>tcs;
    for(int tc = 1; tc<=tcs; tc++){
        solve();
    }

    return 0;
}


```

3. Rest in peace-21-1

```
/*
T(N) = O(N)
S(N) = O(1)
*/

#include<bits/stdc++.h>

using namespace std;

# define ll long long int

void solve(){
	int n;
	cin>>n;
	string s = to_string(n);

	bool found = false;
	for(int i = 0; i + 1<s.size(); i++){
		if(s[i] == '2' && s[i + 1] == '1'){
			found = true;
			break;
		}
	}

	if((n % 21 == 0) || found){
		cout<<"The streak is broken!\n";
	}else{
		cout<<"The streak lives still in our heart!\n";
	}
}

int main(){
	int tcs = 0;
	cin>>tcs;
	for(int tc = 1; tc<=tcs; tc++){
		solve();
	}

	return 0;
}

```
