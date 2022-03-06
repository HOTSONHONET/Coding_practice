#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tcs;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        int n;
        cin >> n;
        vector<int> store;
        int factor = 1;
        while (n)
        {
            if (n % 10 != 0)
            {
                store.emplace_back(factor * (n % 10));
            }
            factor *= 10;
            n /= 10;
        }

        cout << store.size() << endl;
        for (int &i : store)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}