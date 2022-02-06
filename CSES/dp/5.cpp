#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e6 + 1;

int main()
{
    vector<int> dp(maxx, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < maxx; i++)
    {
        int maxDigit = 0, tmp = i;
        while (tmp > 0)
        {
            maxDigit = max(maxDigit, tmp % 10);
            tmp /= 10;
        }
        dp[i] = min(dp[i], 1 + dp[i - maxDigit]);
    }

    int n;
    cin >> n;
    cout << dp[n] << "\n";
    return 0;
}