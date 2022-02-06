
#include <bits/stdc++.h>
using namespace std;


#define ll long long int

vector<int> graph[1001];
vector<pair<ll, vector<ll>>> PATH;

void DFS(ll start, ll end, ll visited[], vector<ll> res, ll secs)
{
    res.push_back(start);
    if (start == end)
    {
        PATH.push_back({secs * (res.size() - 1), res});
        return;
    }
    for (auto v : graph[start])
    {
        if (visited[v] == 0)
        {
            visited[start] = 1;
            DFS(v, end, visited, res, secs);
            visited[start] = 0;
        }
    }
}

int main()
{
    ll N, M, T, C, u, v;
    cin >> N >> M >> T >> C;

    for(int i = 0; i<M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (N <= 2)
        cout << -1 << endl;

    else
    {
        vector<ll> res;
        ll secs = C;
        ll visited[N + 1] = {0};

        // Performing DFS
        DFS(1, N, visited, res, secs);
        if (PATH.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(PATH.begin(), PATH.end());
            set<ll> times;
            for (int j = 0; j<PATH.size(); j++)
            {   ll ans = 0;
                ll trafficTime = 0;          
                for (int i = 1; i < PATH[j].second.size(); i++)
                {
                    ans += C + (trafficTime - ans);
                    while (trafficTime < ans)
                        trafficTime += T;
                }
                times.insert(ans);

                if (times.size() == 2) break;
            }

            if (times.size() == 1) cout<< -1 <<endl;
            else{
            set<ll> :: iterator it;
            ll res;
            for(it = times.begin(); it != times.end(); ++it){
                res = *it;
            }
            cout<< res <<endl;
            }
        }
    }
    return 0;
}