#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    vector<int> v(11, 0);

    string num;
    cin >> num;

    for (auto i : num)
    {
        v[i - '0']++;
    }

    string sorted_string = "";
    for (int i = 1; i < 11; i++)
    {
        for (int j = 0; j < v[i]; j++)
        {
            sorted_string += to_string(i);
        }
    }

    string p1 = "0", p2 = "0";
    ll n = sorted_string.size();
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            p1 += sorted_string[i];
        else
            p2 += sorted_string[i];
    }
    ll x1 = stoi(p1), x2 = stoi(p2);

    cout << (x1 + x2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);

    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; tc++)
        solve();

    return 0;
}