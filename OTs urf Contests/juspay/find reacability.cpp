#include <bits/stdc++.h>
using namespace std;

#define MAXX 1e5
#define nline "\n"

void dfs(int src, vector<int> &visited, vector<vector<int>> &adjL, int dest, bool &found)
{
    if (src == dest)
    {
        found = 1;
        return;
    }
    if (visited[src])
    {
        return;
    }

    visited[src] = 1;
    for (auto &i : adjL[src])
    {
        if (visited[i] == false)
        {
            dfs(i, visited, adjL, dest, found);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adjL(MAXX);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
    }

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adjL[x].push_back(y);
    }
    int A, B;
    cin >> A >> B;

    bool ans = false;
    vector<int> visited(MAXX, 0);
    dfs(A, visited, adjL, B, ans);
    cout << int(ans) << nline;

    return 0;
}