#include <bits/stdc++.h>

using namespace std;

bool isPerfectSq(int x)
{
    int sqrt_X = sqrt(x);
    return sqrt_X * sqrt_X == x;
}

int solve(int n)
{
    if (isPerfectSq(n))
        return 1;

    for (int i = 1; i <= (int)sqrt(n); i++)
        if (isPerfectSq(n - i * i))
            return 2;

    while (n % 4 == 0)
        n >>= 2;

    if (n % 8 == 7)
        return 4;

    return 3;
}

int main()
{

    int n;
    cin >> n;

    int cnt = solve(n);

    cout << cnt << "\n";

    return 0;
}