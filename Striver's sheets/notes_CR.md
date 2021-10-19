# CR sheet solution [👨🏼‍💻](https://docs.google.com/document/d/1L3sbSjPdnoJLBR7vnE-AyDlSGNcd4bcEhu5Rveucpa8/edit)

### Binary Search
* Ternary string

```
void solve(string s)
{
    int ans = INT_MAX;
    int idx1, idx2, idx3;
    idx1 = idx2 = idx3 = -1;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            idx1 = i;
        else if (s[i] == '2')
            idx2 = i;
        else
            idx3 = i;
        if ((idx1 >= 0) && (idx2 >= 0) && (idx3 >= 0))
        {
            int possible_ans = 1 + max(idx1, max(idx2, idx3)) - min(idx1, min(idx2, idx3));
            ans = min(ans, possible_ans);
        }
    }

    cout << (ans == INT_MAX ? 0 : ans) << endl;
}
```

* Book Allocation problem

```
bool isOK(vector<int> A, int mid, int n, int B)
{   
        int pages = 0, done = 1;
        for(int i = 0; i<n; i++)
        {   
            if(A[i] > mid) return false;
            if(A[i] + pages > mid)
            {
                pages = A[i];
                done++;
    
                if(done > B) return false;
    
            }
            else pages += A[i];
        }
    
        return true;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(n < B) return -1;
    
    long long sum = 0;
    for(int i = 0; i<n; i++) 
        sum += A[i];
    int l = 0, r = sum, ans = INT_MAX;

    while(l <= r)
    {
        int mid = l + (r-l)/2;
        if(isOK(A, mid, n, B))
        {   
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return ans;

}

```

* Mixing Water

[Reference](https://www.youtube.com/watch?v=-GUstRI69PI)

```
/* T(N) = O(1), S(N) = O(1) */
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
 
typedef long long int ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
		double h, c, t;
		cin >> h >> c >> t;
		int cups = 1;
		double dif = abs(h-t);
		if (abs((h+c)/2-t) < dif) cups = 2, dif = abs((h+c)/2-t);
	//	cout << dif << " " << cups << "\n";
		if (2*t != h+c) {
			double critical = (t-c)/(2*t-h-c);
			double x1 = ceil(critical), x2 = floor(critical);
			if (x2 > 1) {
				double val1 = abs((x2*h+(x2-1)*c)/(2*x2-1) - t);
			//	cout << val1 << " " << x2 << "\n";
				if (val1 < dif) cups = 2*x2-1, dif = val1; 
			}
			if (x1 > 1) {
				double val1 = abs((x1*h+(x1-1)*c)/(2*x1-1) - t);
			//	cout << val1 << " " << x1 << "\n";
				if (val1 < dif) cups = 2*x1-1, dif = val1; 
			}
		}
		cout << cups << "\n";
	}
    
    
	return 0;
}
```

### Prefix Sum

* Static Range Sum Queries

```
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        long long int tmp;
        cin >> tmp;
        v[i] = v[i - 1] + tmp;
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (v[b] - v[a - 1]) << "\n";
    }
}

int main()
{
    solve();
}

```

* KJ street light problem

![image](https://user-images.githubusercontent.com/56304060/137871538-69f509b0-7508-4ec9-b9a5-dfad482170b8.png)
```
T(N) = O(N), S(N) = O(N)

Idea
====
- Here, we will use Scaline algorithm which is best for solving range queries problems
- Idea is to initiate a array A with N+1 length and fill it with 0s
- Then for each incoming range (start, end, val_to_add) , do this
	A[start] += val_to_add
	A[end + 1] -= val_to_add
- After this use another for loop to calculate the prefix sum
	A[i] += A[i-1] for i = 1 to N
- Scaline algorithm makes the below code to be executable in O(N) time
	for i in #queries
		for j in start:end
			A[i] += val_to_add
			
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> line(p + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x, r;
        cin >> x >> r;
	
	// Using scaline algorithm
        line[max(0, x - r)]++;
        line[min(p, x + r + 1)]--;
    }

    // Calculating the prefix sum
    for (int i = 1; i <= p; i++)
        line[i] += line[i - 1];

    int counter = 0, maxx = 0;
    for (auto i : line)
    {
        if (i != 1)
            counter++;
        else
        {
            maxx = max(maxx, counter);
            counter = 0;
        }
    }
    maxx = max(counter, maxx);
    cout << maxx << "\n";
    return 0;
}

```
* Cherry and Bits (Prefix sum in a matrix)

```

/*

    T(N) = O(N^2), S(N) = O(N^2)
    Idea
    =====
    - Using prefix sum to calculate the no of times we are going to reverse a position M[i][j]
    - So if a number is reversed even times then we dont need to reverse it
    - Else it is odd then we are going to reverse it
    - While doing prefixSum in matrix we preform it in 2-directions
        => Row wise
        => Column wise
*/
void solve()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = s[j] - '0';
        }
    }

    vector<vector<int>> prefixSum(rows, vector<int>(cols, 0));
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;

        prefixSum[x1][y1]++;
        if (x2 + 1 < rows and y2 + 1 < cols)
            prefixSum[x2 + 1][y2 + 1]++;

        if (x2 + 1 < rows)
            prefixSum[x2 + 1][y1]--;
        if (y2 + 1 < cols)
            prefixSum[x1][y2 + 1]--;
    }
    // calculating the prefix sum

    // Row wise
    for (int i = 0; i < rows; i++)
        for (int j = 1; j < cols; j++)
            prefixSum[i][j] += prefixSum[i][j - 1];
    
    //Column wise
    for (int i = 0; i < cols; i++)
        for (int j = 1; j < rows; j++)
            prefixSum[j][i] += prefixSum[j - 1][i];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Reversing odd no of times while printing simply even no of times
            cout << ((prefixSum[i][j] & 1) ? !abs(matrix[i][j]) : matrix[i][j]);
        }
        cout << "\n";
    }
}
```

### Primers/Divisors

* Count the number of primes in a given range

```

/*

T(N) = O(N * log(log(N))), S(N) = O(1e7)

Idea
=====
- Use Seive of Erastosthenes algorithm to pre compute numbers that are primes
- Using a for loop and prefix sum concept calculate the no of primes we can get from o to i for i in range(2 to N)
- Then, for a given range (l, r) we have to simply perform PrefixPrimeCnter[r] - PrefixPrimeCnter[l-1], this is valid for 0< l <= r < MAXX

*/
vector<int> seivePrime(int n)
{
    vector<int> Primes(n, 1);
    for (int i = 2; i <= n; i++)
        if (Primes[i])
            for (int p = 2 * i; p <= n; p += i)
                Primes[p] = 0;

    for (int i = 2; i <= n; i++)
        Primes[i] = Primes[i - 1] + ((Primes[i]) ? 1 : 0);

    return Primes;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int maxx = 1e7;
    vector<int> prefixPrimeCnter = seivePrime(maxx + 1);

    int tcs = 0;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; tc++)
    {
        int cnt = 0;
        int m, n;
        cin >> m >> n;
        cout << (prefixPrimeCnter[n] - prefixPrimeCnter[m - 1]) << endl;
    }

    return 0;
}
```

* Prime generation

![image](https://user-images.githubusercontent.com/56304060/137966167-1c08f411-8da9-42bb-bf4e-7a33475518d6.png)


```
/*

T(N) = O((N^0.5) * log(log(N^0.5)), N^0.5 because we will be primes upto R^0.5
S(N) = O(N)

Idea
====
- We will be using Seive algorithm in a different way so that we can prime number in a given range
- Here, we will use segmented Seive algorithm
- We can't apply simple Seive algorithm because L and R lies between 1 to 10^9, storing that much of numbers will throw MLE
- But we can use the fact that R-L < 10^5, we can apply segmented seive algorithm we will be storing only R-L integers
- Steps:
	=> Store all the marked primes i.e. whose squares are less than R, we will use simple seive algorithm for that 
	=> Create a dummy array of length R-L+1 and fill it with 1s. This will represent all the numbers between L to R
	=> Now use the marked primes, and assign zero to all the indices of dummy which are multiple of those primes
		i.e we will start with the smallest multiple of prime that lies between the range and then we will use the 
		seive concept of increment i.e we will increase the number by the current prime number
	=> Now what ever numbers or indices are marked with 1 are our required primes\
	=> One key thing to catch is that if our l is given as 1 we will shift it 2 so that we can ignore 1 in the start

- for example; l = 1, r = 10
	=> l = l + 1 i.e l = 2
	=> marked primes will be :  [2, 3] because 2 and 3 are primes which are less than 10^0.5
	=> our dummy array will be (initially): [0->1, 1->1, 2->1, 3->1, 4->1, 5->1, 6->1, 7->1, 8->1, 9->1] (index->boot status)
	=> our final ds will be : [0->1, 1->1, 2->0, 3->1, 4->0, 5->1, 6->0, 7->0, 8->0, 9->0,]
	=> Now using a for loop from i = l to r, if i-l index in dummy is set to true or not
	=> Now, as we can see our final output we will be: [1, 2, 3, 5, 7]

*/




vector<int> seivePrime(int n)
{
    vector<int> Primes(n + 1, 1);
    Primes[0] = Primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (Primes[i])
            for (int p = i * i; p <= n; p += i)
                Primes[p] = 0;

    vector<int> primesList;
    for (int i = 2; i <= n; i++)
        if (Primes[i])
            primesList.push_back(i);

    // cout << "PrimeList: ";
    // print(primesList);
    return primesList;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tcs = 0;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; tc++)
    {
        int l, r;
        cin >> l >> r;

        // Because 1 is not a prime number
        if (l == 1)
            l++;

        // Get the list of primes that will mark [l, r]
        vector<int> primes = seivePrime(sqrt(r));

        // Create a data structure(array) to store the primes from [l, r]
        vector<int> ds(r - l + 1, 1);

        // Marking the multiples of primes in the range [l, r]
        for (auto prime : primes)
        {
            int firstMultiple = prime * (l / prime);
            if (firstMultiple < l)
                firstMultiple += prime;
            for (int i = max(firstMultiple, prime * prime); i <= r; i += prime)
                ds[i - l] = 0;
        }

        // print the primes
        for (int i = l; i <= r; i++)
            if (ds[i - l])
                cout << i << "\n";

        cout << "\n";
    }

    return 0;
}
```

* Divisor Analysis

*[Reference](https://usaco.guide/problems/cses-2182-divisor-analysis/solution)*

<table>
  <tr align="center">
    <td># of divisors</td>
    <td>Sum of Divisors</td>
    <td>Product of divisors</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/56304060/138002914-8f9caa37-2c99-4e50-b79a-c13c22713f52.png" width=500 height=200></td>
    <td><img src="https://user-images.githubusercontent.com/56304060/138002838-586c50e8-7d6a-4cf2-99bc-88c7ea3fa0aa.png" width=500 height=200></td>
    <td><img src="https://user-images.githubusercontent.com/56304060/138002887-facbc41d-ff98-4464-a1d7-9dd8ccd8ddc4.png" width=500 height=200></td>
  </tr>
 </table>
 
```
T(N) = O(N * log(MAX(ki))

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

ll expo(ll base, ll power)
{
    ll ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base % MOD;

        base = base * base % MOD;
        power >>= 1;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    ll num_divisors_1 = 1, num_divisors_2 = 1;
    ll divisors_sum = 1;
    ll product_sum = 1;
    for (int i = 0; i < n; i++)
    {
        ll x, k;
        cin >> x >> k;

        // Lets compute the # divisors
        num_divisors_1 = num_divisors_1 * (k + 1) % MOD;

        // Lets compute the sum of divisors
        divisors_sum = divisors_sum * (expo(x, k + 1) - 1) % MOD * expo(x - 1, MOD - 2) % MOD;

        // Lets compute the product of divisors
        product_sum = expo(product_sum, k + 1) * expo(expo(x, (k * (k + 1) / 2)), num_divisors_2) % MOD;
        num_divisors_2 = num_divisors_2 * (k + 1) % (MOD - 1);
    }

    cout << num_divisors_1 << " " << divisors_sum << " " << product_sum << "\n";
}

int main()
{
    solve();
}


```
