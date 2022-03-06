#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int minn = INT_MAX;
    for (int i = 1; i < 101; i++)
    {
        minn = min(minn, abs(x1 - i) + abs(x2 - i) + abs(x3 - i));
    }
    cout << minn << endl;
    return 0;
}
