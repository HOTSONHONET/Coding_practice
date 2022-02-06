#include <bits/stdc++.h>

using namespace std;

int solve(string s, string t)
{
	if (s.size() < t.size())
		return -1;
	map<char, int> tm;
	for (auto i : t)
		tm[i]++;

	int l = s.size(), g = t.size(), i = 0;

	vector<int> v;

	while (i < l - g + 1)
	{
		bool flag = true;
		map<char, int> tmpMap;
		for (int j = i; j < i + g; j++)
		{
			tmpMap[s[j]]++;
		}

		for (auto k : t)
		{
			if (tm[k] != tmpMap[k])
			{
				flag = false;
				break;
			}
		}

		// cout << i << " " << s.substr(i, g) << endl;
		if (flag)
			v.push_back(i);
		i++;
	}

	if (v.size() == 0)
		return -1;
	if (v.size() == 1)
		return 0;
	return v[v.size() - 1] - v[0] - g;
}

int main()
{
	int tcs;
	cin >> tcs;
	while (tcs--)
	{
		string s, t;
		cin >> s >> t;
		cout << solve(s, t) << endl;
	}
}
