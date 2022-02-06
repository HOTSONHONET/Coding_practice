#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n);
    map<int, int> mapper;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        mapper[a[i]], mapper[b[i]];
    }

    int order = 0;
    for (auto &ele : mapper)
    {
        ele.second = order++;
    }

    vector<vector<pair<int, int>>> projects(order);
    for (int i = 0; i < n; i++)
    {
        projects[mapper[b[i]]].emplace_back(mapper[a[i]], p[i]);
    }

    // dp[i] = max amount of money we can make before the starting of ith day
    vector<ll> dp(order, 0);
    for (int i = 0; i < order; i++)
    {
        if (i > 0)
        {
            dp[i] = dp[i - 1];
        }

        for (auto &ele : projects[i])
        {
            dp[i] = max(dp[i], dp[ele.first] + ele.second);
        }

        // cout << dp[i] << " ";
    }
    // cout << "Order : " << order << endl;
    cout << dp[order - 1] << endl;
    return 0;
}