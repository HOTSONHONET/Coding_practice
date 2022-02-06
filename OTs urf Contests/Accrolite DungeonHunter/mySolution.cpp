#include <bits/stdc++.h>
using namespace std;

// T(N) = O(N^2 * log(N))
// S(N) = O(1)

bool isValid(int mid, int n, int m, vector<vector<int>> p, vector<vector<int>> c)
{
    bool flag;
    int s = mid, best_s;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        best_s = s;
        for (int j = 0; j < m; j++)
        {
            if (s - p[i][j] <= 0)
                continue;
            else
            {
                s -= p[i][j];
                best_s = max(best_s, s + c[i][j]);
                s += p[i][j];
                flag = true;
            }
        }

        if (flag == false)
            return false;
        s = best_s;
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tcs = 0;
    cin >> tcs;
    while (tcs--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> p(n, vector<int>(m, 0)), c(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> p[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> c[i][j];

        int maxW = 0, minW = *min_element(p[0].begin(), p[0].end());
        for (auto i : p)
        {
            int maxx = 0, minn = INT_MAX;
            for (auto j : i)
            {
                maxx = max(maxx, j);
                minn = min(minn, j);
            }
            maxW += maxx;
        }

        int pos_ans = -1;
        while (minW <= maxW)
        {
            int mid = minW + (maxW - minW) / 2;
            if (isValid(mid, n, m, p, c))
            {
                maxW = mid - 1;
                pos_ans = mid;
            }
            else
                minW = mid + 1;
        }
        cout << pos_ans << endl;
    }

    return 0;
}