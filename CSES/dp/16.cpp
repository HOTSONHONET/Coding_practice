#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    for (int &i : w)
    {
        cin >> i;
    }

    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};
    for (int s = 1; s < (1 << n); s++)
    {
        dp[s] = {n + 1, 0};
        for (int p = 0; p < n; p++)
        {
            if (s & (1 << p))
            {
                auto option = dp[s ^ (1 << p)]; // inverts the pth bit of s. E.g: 110 ^ 1<<2 -> 010
                if (option.second + w[p] <= W)
                {
                    option.second += w[p];
                }
                else
                {
                    option.first++;
                    option.second = w[p];
                }
                dp[s] = min(dp[s], option);
            }
        }
    }

    cout << dp.back().first << endl;
    return 0;
}