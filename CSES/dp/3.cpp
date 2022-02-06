#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e9 + 7;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> v(n), dp(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int &j : v)
        {
            if (i >= j)
            {
                dp[i] = (dp[i] + dp[i - j]) % maxx;
            }
        }
    }

    cout << dp[k] << "\n";
    return 0;
}