#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M[5][5];
    pair<int, int> pos;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                pos = make_pair(i, j);
            }
        }
    }

    int steps = abs(2 - pos.first) + abs(2 - pos.second);

    cout << steps << endl;

    return 0;
}