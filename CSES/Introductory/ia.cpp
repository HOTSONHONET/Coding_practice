#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ll n, x, y;
	ll res = 0;
	cin >> n;
	cin >> x;
	for (int i = 0; i < n - 1; i++) {
		cin >> y;
		if (y < x) {
			res += x - y;
		}
		else {
			x = y;
		}

	}

	cout << res << endl;
	return 0;
}



