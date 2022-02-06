#include <bits/stdc++.h>
using namespace std;

long long recur(vector<long long> &v, vector<vector<long long>> &dp, long long i, long long j, long long sum)
{
    if (j == i + 1)
    {
        dp[i][j] = max(v[i], v[j]);
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = max(sum - recur(v, dp, i + 1, j, sum - v[i]), sum - recur(v, dp, i, j - 1, sum - v[j]));
    return dp[i][j];
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
    for (long long &i : v)
    {
        cin >> i;
    }
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    cout << recur(v, dp, 0, n - 1, sum)
         << endl;
    return 0;
}