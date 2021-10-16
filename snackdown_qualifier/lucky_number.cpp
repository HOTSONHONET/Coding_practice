#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a == 7 || b == 7 || c == 7) ? "YES" : "NO") << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tcs = 0;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        solve();
    }

    return 0;
}
