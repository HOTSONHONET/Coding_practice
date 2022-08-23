/*
ALL TCS passed

*/

#include <bits/stdc++.h>
using namespace std;

string solve(int S)
{
    // Write your code here
    if (!(S & 1))
    {
        return "-1";
    }
    map<int, int> pageSum = {{0, 1}, {2, 5}, {4, 9}, {6, 13}, {8, 17}};
    vector<int> v1 = {-1};
    for (auto &[k, v] : pageSum)
    {
        if (v <= S)
        {
            v1[0] = k;
        }
    }

    S -= pageSum[v1[0]];

    while (S)
    {
        for (int i = 9; i >= 1; i--)
        {
            if ((S - 2 * i) >= 0)
            {
                v1.push_back(i);
                S -= 2 * i;
                break;
            }
        }
    }

    string ans = "";
    if (v1[0] % 2 == 0)
    {
        for (auto &i : v1)
        {
            ans += to_string(i);
        }

        reverse(ans.begin(), ans.end());
    }
    return ans == "0" ? "1" : ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int S;
        cin >> S;

        string out_;
        out_ = solve(S);
        cout << out_;
        cout << "\n";
    }
}