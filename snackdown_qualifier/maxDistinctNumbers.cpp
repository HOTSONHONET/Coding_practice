#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].second = i;
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());
    vector<pair<ll, ll>> A;
    ll j = 0;

    for (auto i : v)
        (j >= i.first) ? A.push_back({i.second, j}) : A.push_back({i.second, j++});

    sort(A.begin(), A.end(), [](pair<ll, ll> &a, pair<ll, ll> &b)
         { return a.first < b.first; });
    for (auto i : A)
        // cout << "(" << i.first << ", " << i.second << "),  ";
        cout << i.second << " ";
    cout << "\n";
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
