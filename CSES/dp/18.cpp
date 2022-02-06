#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[20][10][2][2];
ll solve(string &number, int n, int x, bool leading_zeros, bool tight)
{
    if (n == 0)
    {
        return 1;
    }
    if (x != -1 && dp[n][x][leading_zeros][tight] != -1)
    {
        return dp[n][x][leading_zeros][tight];
    }
    int lb = 0, ub = tight ? number[number.size() - n] - '0' : 9;

    ll ans = 0;
    for (int dig = lb; dig <= ub; dig++)
    {
        if (dig == x && leading_zeros == 0)
        {
            continue;
        }
        ans += solve(number, n - 1, dig, leading_zeros & dig == 0, tight & (dig == ub));
    }

    return dp[n][x][leading_zeros][tight] = ans;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    string A = to_string(a - 1), B = to_string(b);
    memset(dp, -1, sizeof dp);
    ll ansB = solve(B, B.size(), -1, 1, 1);
    memset(dp, -1, sizeof dp);
    ll ansA = solve(A, A.size(), -1, 1, 1);
    cout << ansB - ansA << endl;
    return 0;
}