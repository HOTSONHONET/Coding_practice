#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxx = 1e9 + 7;
vector<vector<int>> dp;
void generate_masks(int cur_mask, int i, int next_mask, int n, vector<int> &next_masks)
{
    if (i == n + 1)
    {
        next_masks.emplace_back(next_mask);
        return;
    }

    if ((cur_mask & (1 << i)) != 0)
    {
        generate_masks(cur_mask, i + 1, next_mask, n, next_masks);
    }

    if (i != n)
    {
        if ((cur_mask & (1 << i)) == 0 && (cur_mask & (1 << (i + 1))) == 0)
        {
            generate_masks(cur_mask, i + 2, next_mask, n, next_masks);
        }
    }

    if ((cur_mask & (1 << i)) == 0)
    {
        generate_masks(cur_mask, i + 1, next_mask + (1 << i), n, next_masks);
    }
}

int solve(int col, int mask, const int m, const int n)
{
    if (col == m + 1)
    {
        if (mask == 0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[col][mask] != -1)
    {
        return dp[col][mask];
    }

    int ans = 0;
    vector<int> next_masks;
    generate_masks(mask, 1, 0, n, next_masks);

    for (int next_mask : next_masks)
    {
        ans = (ans + solve(col + 1, next_mask, m, n)) % maxx;
    }

    return dp[col][mask] = ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    dp.resize(1001, vector<int>(1 << 11, -1));
    int ans = solve(1, 0, m, n);
    cout << ans << endl;
    return 0;
}