#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxx = 1e9 + 7;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

int n = 1000000;
ll dp[1000001][2];

int main()
{
    fast_io;
    int t = 1; // cin >> t;
    while (t--)
    {
        dp[n + 1][0] = dp[n + 1][1] = 1;

        for (int i = n; i >= 2; i--)
        {
            ll op1 = (dp[i + 1][1] + dp[i + 1][0]) % maxx;
            ll op2 = dp[i + 1][0];
            ll op3 = (2 * dp[i + 1][0]) % maxx;
            ll op4 = dp[i + 1][1];

            dp[i][0] = (op1 + op2 + op3) % maxx;
            dp[i][1] = (op1 + op4) % maxx;
        }

        int q;
        cin >> q;
        while (q--)
        {
            int query;
            cin >> query;
            cout << (dp[1000000 - query + 2][1] + dp[1000000 - query + 2][0]) % maxx << '\n';
        }
    }
    return 0;
}