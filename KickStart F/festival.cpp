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


#include<bits/stdc++.h>

using namespace std;

#define ipair pair<int, int>
#define llpair pair<long long, long long>
#define llipair pair<long long int, long long int>
#define ll long long
#define lli long long int
#define MAX 1000000007
#define ull unsigned long long
#define INF 0x3f3f3f3f

template < typename T > 
void print(vector < T > v)
{
    for (auto i:v)
        cout << i << " ";
      cout << endl;
}


template < typename T > 
void print(vector < pair<T, T> > v)
{   cout<<"[";
    for (auto i:v)
        cout << "{" << i.first << "," << i.second<< "},";
    cout << "]" <<endl;
}

template < typename T > 
ll factorial (T n, ll mod = MAX)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
      ans = (ans * i) % mod;
    }

    return ans;
}


template<typename T>
vector<vector<T>> vector_perms(vector<T> s)
{
    vector<vector<T>> ans;
    do{ 

        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    
    return ans;
}

template<typename T>
vector<string> string_perms(string s)
{
    vector<string> ans;
    do{ 
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    
    return ans;
}

ll npr(ll n, int r)
{
    return factorial(n)/factorial(n-r);
}

ll ncr(ll n, ll r)
{   
    if(n<r) return 0;
    return npr(n, r)/factorial(r);
}

vector<int> split(string s)
{
    vector<int> res;
    for(auto i: s) res.push_back(i - '0');
    return res;
}


template<typename T>
void printPath(vector<T> parent, T j)
{	

	if (parent[j] == - 1)
		return;

	printPath(parent, parent[j]);

    cout<<j;
}

template<typename T>
vector<T> shortestPath(vector<pair<T,T> > adj[], T V, T src)
{
	priority_queue< pair<T, T>, vector <pair<T, T>> , greater<pair<T, T>> > pq;
	vector<T> parent(V);
  	parent[0] = -1;

	vector<T> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		T u = pq.top().second;
		pq.pop();

		for (auto x : adj[u])
		{

			T v = x.first;
			T weight = x.second;

			if (dist[v] > dist[u] + weight)
			{

				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
              	parent[v] = u;
			}
		}
	}

	cout<<"Print shortest distances stored in dist[]"<<endl;
	dist[src] = 0;
	for (T i = 0; i < V; ++i){
		cout<<src<<" -> "<<i<<"->"<<dist[i]<<endl;
    }
    
    return dist;
}

///////////////////////////////Starts from here///////////////////////////////
struct Attracts{

    int h, s, e;
};

bool myComp(ipair a, ipair b)
{
    return a.first < b.first;
}

bool hSort(struct Attracts a, struct Attracts b)
{
    return a.h > b.h;
}

vector<ipair> giveGroups(vector<ipair> groups)
{
    sort(groups.begin(), groups.end(), myComp);
    int idx = 0;
    int n = groups.size();
    for(int i=1; i<n; i++)
    {
        if(groups[idx].second >= groups[i].first)
        {
            groups[idx].second = max(groups[idx].second, groups[i].second);
            groups[idx].first = min(groups[idx].first, groups[i].first);
            
        }else{
            idx++;
            groups[idx] = {groups[i].first, groups[i].second};
        }

    }
    
    vector<ipair> to_return;
	for (int i = 0; i <= idx; i++)
		to_return.push_back({groups[i].first,groups[i].second});
// 	print(groups);
	return to_return;

}

ll solve(int n, int s, int k, vector<Attracts> attracts)
{
    vector<ipair> groups;
    for(auto i: attracts)
    {
        groups.push_back({i.s, i.e});
    }
    
    groups = giveGroups(groups);
    
    vector<vector<Attracts>> groups_map(groups.size());
    
    for(auto i: attracts)
        for(int j = 0; j<groups.size(); j++)
        {
            if(i.s >= groups[j].first and i.e <= groups[j].second)
            {
                groups_map[j].push_back(i);
            }
        }
    
    
    ll ans = 0;    
    
    // print(groups);
    for(auto i: groups_map)
    {   
        // for(auto k : i) cout<<k.s<<" "<<k.e<<" "<<k.h<<endl;
        
        sort(i.begin(), i.end(), hSort);
        ll res = i[0].h;
        int j = 1;
        int s = i.size();
        while(j < min(k, s)-1)
        {
            if(i[j].e >= i[0].s or i[j].s <= i[0].e){
                res += i[j].h;
                cout<<i[j].s<<" "<<i[j].e<<endl;
            }
            j++;
        }
        
        ans = max(ans, res);
    }
    

    return ans;
    // return 0;
}




int32_t main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int tcs = 0;
    cin >> tcs;
    for(int _ = 1; _ <=tcs; _++)
    {   
        int n, d, k;
        cin>>d>>n>>k;
        vector<Attracts> attracts;
        for(int i = 0; i<n; i++)
        {   
            struct Attracts a;
            cin>>a.h>>a.s>>a.e;
            attracts.push_back(a);
        }
        cout<<"Case #"<<_<<": "<<solve(n, d, k, attracts)<<endl;
    }
    return 0;
}








