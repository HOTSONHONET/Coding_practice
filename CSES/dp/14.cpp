#include <bits/stdc++.h>
using namespace std;

const int maxx = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    int total = n * (n + 1) / 2;
    if (total & 1)
    {
        cout << 0 << endl;
        return 0;
    }

    // dp[i][j] = no of ways we can get sum j from 0 to i index
    // that doest not min we are considering all the elements from 0 to i
    vector<vector<int>> dp(n, vector<int>(total + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            int rem = j - i;
            dp[i][j] = (dp[i - 1][j] + ((rem >= 0) ? dp[i - 1][rem] : 0)) % maxx;
        }
    }
    // for (auto &v : dp)
    // {
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n - 1][total / 2] << endl;
    return 0;
}