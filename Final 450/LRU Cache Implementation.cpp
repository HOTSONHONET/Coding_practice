// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        set(key, m[key]->second);
        return m[key]->second;
    }

    void set(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            l.erase(m[key]);
        }
        else
        {
            if (capacity == l.size())
            {
                m.erase(l.back().first);
                l.pop_back();
            }
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends