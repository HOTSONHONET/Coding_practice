#include <bits/stdc++.h>

using namespace std;

int main()
{

    int lines, x = 0;
    cin >> lines;
    while (lines--)
    {
        string op;
        cin >> op;
        if (op == "++X")
        {
            ++x;
        }
        else if (op == "--X")
        {
            --x;
        }
        else if (op == "X++")
        {
            x++;
        }
        else
        {
            x--;
        }
    }

    cout << x << "\n";

    return 0;
}