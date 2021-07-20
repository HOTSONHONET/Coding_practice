#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO" << endl;
    }
    else {
        set<int> left, right;
        if (n % 2 == 0)
        {
            ll cmn_sum = n + 1;
            for (int i = 1; i < n / 2; i += 2) {
                left.insert(i);
                left.insert(cmn_sum - i);
                right.insert(i + 1);
                right.insert(cmn_sum - i - 1);
            }
        }
        else
        {

            if (n == 3)
            {
                left.insert(1);
                left.insert(2);
                right.insert(3);
            }
            else
            {
                ll cmn_sum = n + 4;
                for (int i = 4; i < cmn_sum / 2; i += 2)
                {
                    left.insert(i);
                    left.insert(cmn_sum - i);
                    right.insert(i + 1);
                    right.insert(cmn_sum - i - 1);
                }
                left.insert(1);
                left.insert(2);
                right.insert(3);

            }

        }
        cout << "YES" << endl;
        cout << left.size() << endl;
        for (auto i : left)
        {
            cout << i << " ";
        }
        cout << '\n';
        cout << right.size() << endl;
        for (auto i : right)
        {
            cout << i << " ";
        }
        cout << '\n';

    }



}