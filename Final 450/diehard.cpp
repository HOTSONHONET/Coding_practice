#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int solve(int h, int a, int ele)
{
    if(h<=0 or a<=0) return 0;
    if(dp[h][a] != -1) return dp[h][a];

    int x, y, z;
    x = y = z = 0;

    if(ele != 1) x = 1 + solve(h+3, a+2, 1);
    if(ele != 2) x = 1 + solve(h-5, a-10, 2);
    if(ele != 3) x = 1 + solve(h-20, a+5, 3);
    
    return dp[h][a] = max({x, y, z});
}

int main()
{


	int tcs;
	cin>>tcs;

	while(tcs--)
	{
		int h, a;
        cin>>h>>a;
        
        memset(dp, -1, sizeof(dp));
        cout<<(max({solve(h+3, a+2, 1), solve(h-5, a-10, 2, solve(h-20, a+5, 2))}));

	}
}


// T(n) = O(N^2)
// S(n) = O(N^2)