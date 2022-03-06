#include <bits/stdc++.h>
using namespace std;

#define nline "\n"

const int maxx = 1e5 + 1;
vector<vector<int>> adjL;
vector<int> parent, sizes;

void initialize()
{
    adjL.resize(maxx);
    parent.resize(maxx);
    sizes.resize(maxx, 1);
    iota(parent.begin(), parent.end(), 0);
}

int findParent(int x)
{
    while (x != parent[x])
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

bool find(int a, int b)
{
    return findParent(a) == findParent(b);
}

void makeUnion(int a, int b)
{
    a = findParent(a), b = findParent(b);
    if (sizes[a] < sizes[b])
    {
        parent[a] = parent[b];
        sizes[b] += sizes[a];
        sizes[a] = 0;
    }
    else
    {
        parent[b] = parent[a];
        sizes[a] += sizes[b];
        sizes[b] = 0;
    }
}

void solve()
{
    int n;
    cin >> n;
    initialize();
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
    }

    int edges;
    cin >> edges;
    for (int e = 0; e < edges; e++)
    {
        int x, y;
        cin >> x >> y;
        adjL[x].push_back(y);
        makeUnion(x, y);
    }

    int A, B;
    cin >> A >> B;

    for (auto &i : adjL[B])
    {
        if (find(i, A))
        {
            cout << i << " ";
        }
    }

    cout << nline;
}

int main()
{
    solve();
    return 0;
}