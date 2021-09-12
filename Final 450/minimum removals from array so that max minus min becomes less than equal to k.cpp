// C++ program for the above approach
#include<bits/stdc++.h>
using namespace std;

// To sort the array and return the answer
int removals(int arr[], int n, int k)
{

// sort the array
sort(arr, arr + n);
int dp[n];

// fill all stated with -1
// when only one element
for(int i = 0; i < n; i++)
	dp[i] = -1;

// as dp[0] = 0 (base case) so min
// no of elements to be removed are
// n-1 elements
int ans = n - 1;
dp[0] = 0;
for (int i = 1; i < n; i++)
{
	dp[i] = i;
	int j = dp[i - 1];
	while (j != i && arr[i] - arr[j] > k)
	{
	j++;
	}
	dp[i] = min(dp[i], j);
	ans = min(ans, (n - (i - j + 1)));
}
return ans;
}

// Driver code
int main()
{
int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
int n = sizeof(a) / sizeof(a[0]);
int k = 4;
cout<<removals(a, n, k);
return 0;
}

// This code is contributed by Balu Nagar
