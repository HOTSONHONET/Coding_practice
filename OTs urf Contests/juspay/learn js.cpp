#include <bits/stdc++.h>

using namespace std;

#define MAXX 1e5
#define nline "\n"

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> finder;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        finder[x] = INT_MAX;
    }

    vector<vector<pair<int, int>>> adjL(MAXX);
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int p, q, d;
        cin >> p >> q >> d;
        adjL[p].push_back({q, d});
    }

    int A, B;
    cin >> A >> B;

    set<pair<int, int>> s;
    finder[A] = 0;
    s.insert({0, A});
    while (s.empty() == false)
    {
        auto tmp = *(s.begin());
        s.erase(s.begin());
        int u = tmp.second;
        for (auto i = adjL[u].begin(); i != adjL[u].end(); i++)
        {
            int v = (*i).first, w = (*i).second;
            if (finder[v] > finder[u] + w)
            {
                if (finder[v] != INT_MAX)
                {
                    s.erase(s.find({finder[v], v}));
                }

                finder[v] = finder[u] + w;
                s.insert({finder[v], v});
            }
        }
    }

    cout << (finder[B] == INT_MAX ? -1 : finder[B]) << nline;

    return 0;
}