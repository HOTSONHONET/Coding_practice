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

### Hashing

1. Maximum occurrence

```
/*

T(N) = O(N)
S(N) = O(1)
*/

#include<bits/stdc++.h>

using namespace std;

# define ll long long int


int main(){
	string s;
	getline(cin, s);

	map<char, int> finder;
	for(char &c: s){
		finder[c]++;
	}

	char char_;
	int freq = INT_MIN;
	for(auto [k,v] : finder){
		if(freq < v){
			char_ = k;
			freq = v;
		}
	}

	cout<<char_<<" "<<freq<<endl;
	return 0;
}

```

2. 4C- Registration System
```

/*

T(N) = O(32 * Nlog(N)) ~ O(NlogN) 
S(N) = O(N)
*/
#include <bits/stdc++.h>

using namespace std;

#define ipair pair<int, int>
#define llpair pair<long long, long long>
#define llipair pair<long long int, long long int>
#define ll long long
#define lli long long int
#define ull unsigned long long
#define MAX 1000000007
#define ull unsigned long long
#define INF 0x3f3f3f3f

#ifndef ONLINE_JUDGE
#include "helper_functions.h"
#endif
map<string, int> finder;
void solve()
{
    string s;
    cin >> s;

    if (finder.find(s) != finder.end())
    {
        string newS = s + to_string(finder[s]);
        finder[s]++;
        finder.insert({newS, 1});

        cout << newS;
    }
    else
    {
        finder.insert({s, 1});
        cout << "OK";
    }

    cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    int tcs = 0;
    cin >> tcs;
    finder.clear();
    for (int tc = 1; tc <= tcs; tc++)
    {
        solve();
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}

```

3. OR in Matrix

```
/*

T(N) = O(N * M * max(M, N))
S(N) = O(N * M)

*/

#include <bits/stdc++.h>

using namespace std;

#define ipair pair<int, int>
#define llpair pair<long long, long long>
#define llipair pair<long long int, long long int>
#define ll long long
#define lli long long int
#define ull unsigned long long
#define MAX 1000000007
#define ull unsigned long long
#define INF 0x3f3f3f3f

#ifndef ONLINE_JUDGE
#include "helper_functions.h"
#endif

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n, 1)), b(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];

            if (b[i][j] == 0)
            {
                for (int k = 0; k < max(m, n); k++)
                    a[k % m][j] = a[i][k % n] = 0;
            }
        }
    }

    // Checking
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int or_res = 0;
            for (int k = 0; k < max(m, n); k++)
            {
                or_res |= (a[k % m][j] | a[i][k % n]);
            }
            if (or_res != b[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (vector<int> &i : a)
    {
        for (int &j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    // int tcs = 0;
    // cin >> tcs;
    // for (int tc = 1; tc <= tcs; tc++)
    // {
    //     solve();
    // }

    solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
```

### Prefix Sum

1. Cumulative Sum Query

```
/*

T(N) = O(N)
S(N) = O(N)

*/


void solve()
{
    int n, q;
    cin >> n;
    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }

    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ps[r + 1] - ps[l] << "\n";
    }
}
```


### Bit Manipulation

1. Determining Numbers

```
/*
T(N) = O(N)
S(N) = O(N)
*/

#include<bits/stdc++.h>

using namespace std;

# define ll long long int


int main(){
	int n;
	cin>>n;
	if(n < 2){
		cout<<-1<<" "<<-1<<endl;
	}
	
	int a = 0, v[n];
	for(int i = 0; i<n; i++){
		cin>>v[i];
		a ^= v[i];
	}

	// Choosing the MSB
	int numBits = (int)(log2(a)) + 1;
	int b = a;
	for(int i = 0; i<n; i++){
		if(v[i] & (1<<(numBits - 1)))
			a ^= v[i];
	}

	b ^= a;
	cout<<min(a, b)<<" "<<max(a, b)<<endl;
	return 0;
}

```

2. Powers of Two

```
/*
T(N) = O(32 * log(N) + k * log(N) + k) ~ O(k * logN)
S(N) = O(N)
*/


void solve()
{
    ll n, k, sum;
    cin >> n >> k;
    map<ll, ll> finder;
    queue<ll> q;

    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i))
        {
            if (i > 0)
                q.push((ll)(1 << i));
            finder[(ll)(1 << i)]++;
        }
    }

    if (finder.size() > k)
    {
        cout << "NO\n";
        return;
    }
    int cnt = finder.size();
    while (cnt < k && !q.empty())
    {
        ll top = q.front();
        q.pop();
        finder[top]--;
        finder[top >> 1] += 2;
        if ((top >> 1) > 1)
        {

            q.push(top >> 1);
            q.push(top >> 1);
        }

        cnt++;
    }

    if (cnt < k)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto &[k, v] : finder)
    {
        for (int i = 0; i < v; i++)
        {
            cout << k << " ";
        }
    }
    cout << endl;
}
```

3. You are given two binary strings

```
/*

T(N) = O(N)
S(N) = O(1)

*/

void solve()
{
    string x, y;
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int idx_y = y.find('1');
    int idx_x = x.find('1', idx_y);
    cout << (idx_x - idx_y) << "\n";
}
```

4. Neko Performs Cat Furrier Transform

```
/*
T(N) = O(N) + O(logN)
S(N) = O(1)
*/


void solve()
{
    int n;
    cin >> n;
    if (((n + 1) & n) == 0)
    {

        cout << 0 << endl;
        return;
    }
    int odd = 1, moves = 0;
    vector<int> v;
    while (((n + 1) & n))
    {
        if (odd)
        {
            odd = 0;
            int numBits = 1 + int(log2(n));
            while (n & (1 << numBits))
            {
                numBits--;
            }
            n ^= ((1 << numBits) - 1);
            v.push_back(numBits);
        }
        else
        {
            odd = 1, n++;
        }
        moves++;
    }

    cout << moves << "\n";
    for (int &i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}

```
5. New Year and Old property

```
/*
T(N) = O(MaxBits * MaxBits * MaxBits) where, MaxBits = log(max(l, r))
S(N) = O(MaxBits) <- For string creation

*/


void solve()
{
    ll l, r;
    cin >> l >> r;
    ll numBitsL = 1 + int(log2(l)), numBitsR = 1 + int(log2(r));
    int ans = 0;
    while (numBitsL <= numBitsR)
    {
        string s = "";
        for (int i = 0; i < numBitsL; i++)
        {
            s += '1';
        }
        for (int i = numBitsL - 1; i > 0; i--)
        {
            s[i] = '0';
            ll val = (ll)stoll(s, nullptr, 2);
            if ((val >= l) && (val <= r))
            {
                ans++;
            }
            s[i] = '1';
        }
        numBitsL++;
    }
    cout << ans << "\n";
}
```
