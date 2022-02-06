#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e7;
int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> v(n), dp(k + 1, maxx);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int &j : v)
        {
            if (i >= j && dp[i - j] != maxx)
            {
                dp[i] = min(dp[i], 1 + dp[i - j]);
            }
        }
    }

    cout << (dp[k] == maxx ? -1 : dp[k]) << "\n";
    return 0;
}