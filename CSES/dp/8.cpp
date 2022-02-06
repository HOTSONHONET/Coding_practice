#include <bits/stdc++.h>
using namespace std;

const int maxx = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (v[i] == 0 || v[i] == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }

            else
            {
                if (v[i] == 0 || v[i] == j)
                {
                    dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % maxx + dp[i - 1][j + 1]) % maxx;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n][i]) % maxx;
    }
    cout << ans << "\n";
    return 0;
}