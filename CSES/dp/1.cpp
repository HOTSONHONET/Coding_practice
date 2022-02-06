#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && j <= i; j++)
        {

            dp[i] = (dp[i] + dp[i - j]) % maxx;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}