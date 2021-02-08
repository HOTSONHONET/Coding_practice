#include<bits/stdc++.h>

using namespace std;



int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	string s;
	cin >> s;


	char a = s[0];
	int count = 0, max_count = 0;
	for (auto i : s) {
		if (i == a) count++;
		else {
			a = i;
			max_count = max(max_count, count);
			count = 1;

		}
	}
	max_count = max(max_count, count);
	cout << max_count << endl;


	return 0;
}



