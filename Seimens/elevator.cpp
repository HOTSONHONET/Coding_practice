#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < sizeof(int) * 8; i++)
		if (n & (1 << i))
			cnt++;
	cout << cnt << "\n";

	return 0;
}