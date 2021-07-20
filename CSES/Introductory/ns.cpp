#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve(ll col, ll row) {
    ll max_val = max(col, row);
    ll min_val = min(col, row);
    ll ans;
    ll corner_val = max_val * max_val - max_val + 1;
    if (max_val % 2 == 0) {
        if (row > col) {
            ans = corner_val + (max_val - min_val);
        } else {
            ans = corner_val - (max_val - min_val);
        }
    }
    else {
        if (row > col) {
            ans = corner_val - (max_val - min_val);
        } else {
            ans = corner_val + (max_val - min_val);
        }

    }

    cout << ans << endl;
    return;
}


int main() {
    ll tcs, col, row;
    cin >> tcs;
    for (int tc = 0; tc < tcs; tc++) {
        cin >> row >> col;
        solve(col, row);
    }
}