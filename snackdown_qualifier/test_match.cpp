#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int matches = 5, ind_wins = 0, eng_wins = 0, tmp;
    while (matches--)
    {
        cin >> tmp;
        if (tmp == 1)
            ind_wins++;
        else if (tmp == 2)
            eng_wins++;
    }

    if (ind_wins > eng_wins)
        cout << "INDIA" << endl;
    else if (eng_wins > ind_wins)
        cout << "ENGLAND" << endl;
    else
        cout << "DRAW" << endl;
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
