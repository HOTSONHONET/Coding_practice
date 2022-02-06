#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> pages(n), prices(n), dp(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = x; i >= 0; i--)
        {
            if (i >= prices[j])
            {
                dp[i] = max(dp[i], max(dp[i - 1], pages[j] + dp[i - prices[j]]));
            }
        }
    }

    cout << dp[x] << " ";
    return 0;
}
