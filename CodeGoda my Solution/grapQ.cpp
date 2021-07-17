#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define MAX 1e7
#define llpair pair<ll, ll> 
#define ipair pair<int, int>


class Solution{
    public:
        map<string, bool> visited;
        
        
        map<ll, ll> dijkstra(ll v, ll src, map<int, vector<llpair>> adj)
        {
            priority_queue<llpair, vector<llpair>, greater<llpair>> pq;
            vector<ll> dist(v+1, MAX);
            dist[src] = 0;
            pq.push({0, src});
            while(!pq.empty())
            {
                ll u = pq.top();;
                pq.pop();
                vector<llpair> :: iteratir it;
                for(it=adj[u]; it!=adj[u].end(); ++it){
                    ll v = (*it).first;
                    ll d = (*it).second;
                    if(dist[v] > dist[u] + d)
                    {
                        dist[v] = dist[u] + d;
                        pq.push({dist[v], v});
                    }
                }
            }
            map<ll, ll> shortestPaths;
            for(int i = 1; i<=v; i++)
            {
                shotestPaths[i] = dist[i];
            }
            
            return shortestPaths;
        }

        void solve(ll v, ll cost_travel, map<int, map<int, vector<llpair>> adj, ll t,   map<string, map<string, ll>> hotels){
            
            map<ll, ll> shortestPaths = dijkstra(v, t, adj);
            map<ll, vector<string>> city2Hotels;
            for(auto i: hotels)
            {
                string name = i.first;
                ll city = i.second["city"];
                city2Hotels[city].push_back(name);
            }
            
            map<ll, string> finalMap;
            for(auto i: cityHotels)
            {   
                ll totalCost = 0;
                totalCost = (shortestPath[i.first]*cost_travel) + (hotels[i.second]["cost"]);
                finalMap[totalCost] = i.second;
            }
            
            for(auto i: finalMap){
                cout<<i.second<<" "<<i.first<<endl;
            }
        }

        
};



int main(){
    
    ll n,c;
    cin>>n>>c;
    ll tmpN = n;
    map<int, vector<llpair>> adj;
    while(n--){
        ll u, v, d;
        cin>>u>>v>>d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    
    ll k;
    cin>>k;
    map<string, map<string, ll>> hotels;
    while(k--)
    {
        char s;
        cin>>s;
        if(s == 'H')
        {   
            string name;
            cin>>name;
            ll city, cost;
            hotels[name] = {{"city", u}, {"cost", cost}};
        }

        else{
            ll t;
            cin>>t;
            Solution obj;
            obj.solve(tmpN, c, adj, t, hotels);
        }        
    }

    
    
    return 0;
}