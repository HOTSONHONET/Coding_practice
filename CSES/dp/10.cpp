#include <bits/stdc++.h>
using namespace std;

const int maxx = 501;
int main()
{
    vector<vector<int>> dp(maxx, vector<int>(maxx, 0));
    for (int i = 1; i < maxx; i++)
    {
        for (int j = 1; j < maxx; j++)
        {
            if (i == j)
            {
                dp[i][j] = dp[j][i] = 0;
            }
            else
            {
                dp[i][j] = dp[j][i] = INT_MAX;
                for (int k = 1; k <= min(i, j); k++)
                {
                    dp[i][j] = dp[j][i] = min(dp[i][j], 1 + min(dp[i - k][j] + dp[k][j], dp[i][j - k] + dp[i][k]));
                }
            }
        }
    }
    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << "\n";
    return 0;
}
