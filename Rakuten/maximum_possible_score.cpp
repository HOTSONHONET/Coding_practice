/*
TC 2, 3, 4 failed


*/

/*
    Code by HOTSON HONET
     ______________________
    |					 |
    |					 |
    |                    |
    |                    |
    |                    |
    |                    |
__________________________________
    |\       /          /
    | \_____/          /
    |  \              /
    |   \            /
    |    \///////////
    /\    \/////////
   /__\    \______/

*/

#include <bits/stdc++.h>

#define ipair pair<int, int>
#define llpair pair<long long, long long>
#define llipair pair<long long int, long long int>
#define ll long long
#define lli long long int
#define ull unsigned long long
#define MAXX 1000000009
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define nline "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

#ifndef ONLINE_JUDGE
#include "helper_functions.h"
#else
#define print(...) 42
#endif

long long maximumPossibleScore(int n, vector<long long> arr)
{
    // Write your code here
    vector<vector<int>> v(n, vector<int>(32, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            v[i][31 - j] = (bool)(arr[i] & (1 << j));
        }
    }
    print(v);
    vector<int> s(32, 0);
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s[i] += v[j][i];
        }
    }

    print(s);

    vector<int> element_score(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            element_score[i] += (v[i][j] ? (n - s[j]) : s[j]);
        }
    }
    print(element_score);
    auto req_idx = max_element(element_score.begin(), element_score.end()) - element_score.begin();
    int req_ele = arr[req_idx];
    ll ans = 0LL;
    for (auto &i : arr)
    {
        ans += (req_ele ^ i);
    }

    return ans;
}

void solve()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i_A = 0; i_A < N; i_A++)
    {
        cin >> A[i_A];
    }

    print(A);
    long long out_;
    out_ = maximumPossibleScore(N, A);
    cout << out_;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input_output/input.txt", "r", stdin);
    freopen("input_output/error.txt", "w", stderr);
    freopen("input_output/output.txt", "w", stdout);
#endif
    fastio;
    int tcs = 1;
    //  cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}