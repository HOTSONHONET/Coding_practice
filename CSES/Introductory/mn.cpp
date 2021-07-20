#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ll n;
	cin >> n;

	ll sum = 0;
	for (ll i = 1; i < n; i++) {
		ll tmp;
		cin >> tmp;
		sum += tmp;
	}

	ll res = n * (n + 1) / 2 - sum;
	cout << res << endl;




	return 0;
}