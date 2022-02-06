#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<char> mapper;
    for (char i = '0'; i <= '9'; i++)
        mapper.push_back(i);

    string x;
    cin >> x;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        int val = x[i] - '0';
        char c = x[i];
        if ((val > 9 - val) && !(val == 9 && i == 0))
        {
            string tmp = x;
            for (int j = i; j < n; j++)
            {
                if (tmp[j] == c)
                {
                    tmp[j] = mapper[9 - val];
                }
            }
            x = min(x, tmp);
        }
    }

    cout << x << "\n";
    return 0;
}