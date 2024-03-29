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

using namespace std;

#define ipair pair<int, int>
#define llpair pair<long long, long long>
#define llipair pair<long long int, long long int>
#define ll long long
#define lli long long int
#define MAX 1000000007
#define ull unsigned long long
#define INF 0x3f3f3f3f

//////////////////////////// HELPER FUNCTIONS ////////////////////////////
template <typename T>
void print(vector<T> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

template <typename T>
void print(vector<pair<T, T>> v)
{
    cout << "[";
    for (auto i : v)
        cout << "{" << i.first << "," << i.second << "},";
    cout << "]" << endl;
}

template <typename T>
void printMat(vector<vector<T>> mat, T n, T m)
{
    cout << "Printing matrix" << endl;
    for (T i = 0; i < n; i++)
        print(mat[i]);
}

template <typename T>
ll factorial(T n, ll mod = MAX)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        ans = (ans * i) % mod;
    }

    return ans;
}

template <typename T>
vector<vector<T>> vector_perms(vector<T> s)
{
    vector<vector<T>> ans;
    do
    {

        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    return ans;
}

template <typename T>
vector<string> string_perms(string s)
{
    vector<string> ans;
    do
    {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    return ans;
}

ll npr(ll n, int r)
{
    return factorial(n) / factorial(n - r);
}

ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    return npr(n, r) / factorial(r);
}

vector<int> split(string s)
{
    vector<int> res;
    for (auto i : s)
        res.push_back(i - '0');
    return res;
}

template <typename T>
void printPath(vector<T> parent, T j)
{

    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    cout << j;
}

template <typename T>
vector<T> shortestPath(vector<pair<T, T>> adj[], T V, T src)
{
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> pq;
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

    cout << "Print shortest distances stored in dist[]" << endl;
    dist[src] = 0;
    for (T i = 0; i < V; ++i)
    {
        cout << src << " -> " << i << "->" << dist[i] << endl;
    }

    return dist;
}

ll expo(ll base, ll power)
{
    ll ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base % MAX;

        base = base * base % MAX;
        power >>= 1;
    }

    return ans;
}

vector<int> seivePrimes(int n)
{
    vector<int> Primes(n + 1, 1);
    Primes[0] = Primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (Primes[i])
            for (int p = i * i; p <= n; p += i)
                Primes[p] = 0;

    // vector<int> primesList;
    // for (int i = 2; i <= n; i++)
    //     if (Primes[i])
    //         primesList.push_back(i);
    // return primesList;

    return Primes;
}

vector<ll> giveAllSubsetSum(vector<int> arr)
{

    vector<ll> to_return;
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sum += arr[j];

        to_return.push_back(sum);
    }

    return to_return;
}

ll gcd(ll a, ll b)
{
    ll minn = min(a, b);
    ll maxx = max(a, b);

    if (maxx % minn == 0)
        return minn;
    while (maxx >= minn)
        maxx -= minn;

    return maxx;
}

//////////////////////////// END OF HELPER FUNCTIONS ////////////////////////////

void solve()
{

    ll n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << "YES"
             << "\n"
             << 0 << endl;
        return;
    }
    if (k & 1)
    {
        ll tmp = 0;
        for (ll i = 31; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                tmp = i + 1;
                break;
            }
        }

        cout << "YES"
             << "\n";
        k = (k + (1 << tmp) - 1) / 2;
        cout << tmp << "\n";
        ll ans = 1;
        vector<int> v;
        for (ll i = tmp - 2; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                v.push_back((ans));
                ans += (1 << i);
            }
            else
            {
                ans -= (1 << i);
                v.push_back(ans);
            }
        }

        for (int i = tmp - 2; i >= 0; i--)
            cout << v[i] << "\n";
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tcs = 0;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; tc++)
        solve();

    return 0;
}
