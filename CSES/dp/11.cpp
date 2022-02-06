#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    const int maxx = n * 1000;
    vector<vector<int>> dp(n + 1, vector<int>(maxx + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxx; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1])
            {
                dp[i][j] |= dp[i - 1][j - v[i - 1]];
            }
        }
    }

    int num = count(dp[n].begin() + 1, dp[n].end(), 1);
    cout << num << "\n";
    for (int i = 1; i <= maxx; i++)
    {
        if (dp[n][i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}