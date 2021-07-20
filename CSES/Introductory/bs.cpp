#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
	ll n, ans = 2;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		ans = 2 * ans % ((int)1e9 + 7);
	}
	cout << ans << endl;

}