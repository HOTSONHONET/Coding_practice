#include<bits/stdc++.h>

using namespace std;

#define ll long long

// Idea : total no of ways we can place two knights in a chess board - (total no of ways two knights can attack each other)
// Total no of ways we can place two knights in a NxN chess board - N*N C 2 (combination)
// Total no of ways two knights can attack each other = no of (2x3) and (3x2) rectangles possible in the chess board
// i.e 2x(N-1)x(N-2)
// Since knights attack in L shape manner so total no of L shape is basically the above count
// Also, since we have 2 knights it will be 2x2x(N-1)x(N-2)
// ANS = N*N C 2 - 2x2x(N-1)x(N-2)



int main() {
	ll n, ans;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ans =  ((i * i) * (i * i - 1) / 2 ) - (4 * (i - 1) * (i - 2));
		cout << ans << endl;
	}

}