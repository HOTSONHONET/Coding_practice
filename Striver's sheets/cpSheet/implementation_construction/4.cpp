#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int total_drink = k * l, total_limeCuts = c * d;

	int ans = 0;
	while (total_drink >= n * nl && total_limeCuts >= n && p >= n * np)
	{
		ans++;
		total_drink -= n * nl;
		total_limeCuts -= n;
		p -= n * np;
	}

	cout << ans << endl;
	return 0;
}