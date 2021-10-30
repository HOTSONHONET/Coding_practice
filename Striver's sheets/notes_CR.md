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

### Divide annd Conquer

* Inversion count
```
"""
T(N) = O(N * log(N)), S(N) = O(N)

Idea
=====
- We will use merge sort algorithm to find the num of inversion pairs
- The motivation behind this is to use the merge function where do this step
	if( A[i] <= A[j])
		tmp[k++] = A[i++]
	else tmp[k++] = A[j]
- Now in this step, both the left hand array segment and right hand segment will be sorted so for if we found an element (lets say A[j]) in the right side which is
smaller than some A[i], then it will be smaller than all the elements from A[i to mid - 1] {Here, mid - 1 because, right segment is from mid to right's end}
- Thus, We can compute the total inversions for that particular number in the right for the merge step, which will be (mid - i) elements, so our modified algorithm will be
	if( A[i] <= A[j])
		tmp[k++] = A[i++]
	else{
		tmp[k++] = A[j]
		inv_count = inv_count + (mid - i)
	}


"""


def solver(arr, tmp, l, mid, r):
    i, j, k = (l, mid, l)
    inv = 0
    while(i <= mid-1 and j <= r):
        if(arr[i] <= arr[j]):
            tmp[k] = arr[i]
            k += 1
            i += 1
        else:
            tmp[k] = arr[j]
            j += 1
            k += 1
            inv += mid - i

    while(i <= mid-1):
        tmp[k] = arr[i]
        i += 1
        k += 1

    while(j <= r):
        tmp[k] = arr[j]
        j += 1
        k += 1

    for i in range(l, r + 1):
        arr[i] = tmp[i]

    return inv


def caller(arr, tmp, l, r):
    inv = 0
    if(r > l):
        mid = (l + r) >> 1
        inv += caller(arr, tmp, l, mid)
        inv += caller(arr, tmp, mid + 1, r)

        inv += solver(arr, tmp, l, mid + 1, r)

    return inv


def solve():
    cleaner = input()
    n = int(input())
    arr = []
    for i in range(n):
        tmp = int(input())
        arr.append(tmp)

    tmp_arr = [0]*len(arr)
    return caller(arr, tmp_arr, 0, len(arr) - 1)


if __name__ == "__main__":
    tcs = int(input())
    while(tcs > 0):
        print(solve())
        tcs -= 1


```
* Meet in the middle
```
/* 

T(N) = O(N * 2^N/2), S(N) = O(N/2) = O(N)

Idea
====
- This algorithm can only be implemented for those values of N which satisfies N/2 < 31, because 2^31 will throw MLE
- Idea is to divide our task of generating subset sums into 2 parts
- We will separately find all the subset sums for indices 0 to N/2 and then for N/2 to N. 
- We will be storing the subset sums in 2 arrays
- Now we will sort one of the array
- Then we will try to find (we will use binary search; upper_bound and lower_bound) if we can get any pair between the arrays whose sum is equal to our target
- examples:
	A = [1, 2, 3, 2], target = 5
	l_seg = [1, 2], r_seg = [3, 2]
	left_subset_sums = [0, 1, 3, 2] (using bit magic algorithm we can find all the subset sum)
	right_subset_sums = [0, 3, 5, 2]
	
	lets sort right_subset_sums = [0, 2, 3, 5]
	
	for i in left_subset_sums
		binarySearch(right_subset_sums, target - i) 
			ans += number of (i, target - i)


*/

#include <bits/stdc++.h>
 
using namespace std;
 
/* Using Meet in the middle alogorithm */
 
#define ll long long
 
vector<ll> giveSum(vector<int> arr)
{
    vector<ll> to_return;
    for (int i = 0; i < (1 << arr.size()); i++)
    {
        ll sum = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (i & (1 << j))
                sum += arr[j];
        }
        to_return.push_back(sum);
    }
 
    return to_return;
}
 
void solve()
{
    int n, t;
    cin >> n >> t;
 
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        (i < n / 2) ? v1.push_back(tmp) : v2.push_back(tmp);
    }
 
    vector<ll> x = giveSum(v1), y = giveSum(v2);
 
    /*
 
        1 2 3 2
 
        l = {1, 3, 2}
        r = {3, 5, 2}
 
        l + r = {(3, 2), (2, 3)}
 
        ans = {(5,), (3, 2), (2, 3)}
 
    */
 
    ll ans = 0;
    sort(y.begin(), y.end());
 
    for (auto i : x)
    {
 
        int p = upper_bound(y.begin(), y.end(), t - i) - lower_bound(y.begin(), y.end(), t - i);
        ans += p;
    }
 
    cout << (ans) << "\n";
}
 
int main()
{
    solve();
}

```
* Funny Knapsack
```
/*

T(N) = O(N * 2^(N/2), S(N) = O(N)

Idea
====
- Apply meet in the middle algorithm
- the trick here is we only need to find the upperbound for target - i in y, for all i in x
- so all the elements from 0 to upper_bound we will proper pairs for current i value
- so we will update ans by upper_bound - y.begin()
*/

#define ll long long
vector<ll> giveAllSubsetSum(vector<int> arr)
{

    vector<ll> to_return;
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sum += arr[j];

        to_return.push_back(sum);
    }

    return to_return;
}

void solve()
{
    unordered_set<int> finder;
    int n, w;
    cin >> n >> w;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        (i & 1) ? v1.push_back(tmp) : v2.push_back(tmp);
    }
    vector<ll> x = giveAllSubsetSum(v1), y = giveAllSubsetSum(v2);
    sort(y.begin(), y.end());
    ll ans = 0;
    for (auto i : x)
        ans += upper_bound(y.begin(), y.end(), w - i) - y.begin();

    cout << ans;
}
```

### Strings

* Pattern searching algorithm

	- Rabin Karp (slow algorithm) - TC = O(N\*M) depends upon the hashValue, SC = O(1)
	- KMP and Z algorithm are the best algorithm - TC = O(N), SC = O(N)
	- References
		- [Rabin Karp](https://www.programiz.com/dsa/rabin-karp-algorithm)
		- [KMP algorthim](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
		- [Z algorithm] -> Competitive programming HandBook

```
#include <bits/stdc++.h>

using namespace std;

/* Using Meet in the middle alogorithm */

#define ll long long

// KMP algorithm
vector<int> buildLPS(string pattern)
{
    int n = pattern.size();
    vector<int> lps(n);

    int len = 0, i = 1;
    lps[0] = 0;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int kmp(string str, string pattern)
{
    int n, m;
    n = str.size();
    m = pattern.size();

    vector<int> lps = buildLPS(pattern);
    int indices = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        if (str[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            indices++;
            j = lps[j - 1];
        }
        else if (pattern[j] != str[i] and i < n)
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return indices;
}

// Z algorithm
vector<int> buildZArray(string s)
{
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;

    for (int i = 1; i < n; i++)
    {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
        {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }

    return z;
}

int zAlgotithm(string s, string pattern)
{
    string comb = pattern + "$" + s;
    vector<int> zArray = buildZArray(comb);
    // for (auto i : zArray)
    //     cout << i << " ";
    // cout << "\n";
    int ans = 0;
    for (auto u : zArray)
        if (u == (int)pattern.size())
            ans++;

    return ans;
}

// Rabin Karp Alogrithm
// Slow algorthim : Giving TLE in CSES
long long rabinKarpAlgorithm(string txt, string pattern)
{
    long long n = txt.size(), m = pattern.size();
    long long i, j, pattern_HASH = 0, string_HASH = 0, h = 1, d = n;
    /*

    The value of the MOD depends upon the user
    the more the better we are reducing spurious collision/hit
    but at the same time we are increasing the data type size
    requirement.

    */
    const long long MOD = n + m;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % MOD;

    // Calculating the hash value of the pattern
    for (i = 0; i < m; i++)
    {
        pattern_HASH = (d * pattern_HASH + pattern[i]) % MOD;
        string_HASH = (d * string_HASH + txt[i]) % MOD;
    }

    // Finding the match
    long long cnt = 0;
    for (long long i = 0; i <= n - m; i++)
    {
        if (pattern_HASH == string_HASH)
        {
            for (j = 0; j < m; j++)
                if (txt[i + j] != pattern[j])
                    break;
            if (j == m)
                cnt++;
        }

        if (i < n - m)
        {
            // Updating the string hash vale
            string_HASH = (d * (string_HASH - txt[i] * h) + txt[i + m]) % MOD;

            if (string_HASH < 0)
                string_HASH = string_HASH + MOD;
        }
    }

    return cnt;
}

void solve()
{
    string str, pattern;
    cin >> str >> pattern;
    long long numIndices = rabinKarpAlgorithm(str, pattern);
    cout << numIndices << "\n";
}

int main()
{
    solve();
}

```
* Manachars Algorithm (longest palindromic substing)

	- [Reference](https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/)
```
/* 

T(N) = O(N), S(N) = O(N) 

Idea
=====
- Store the tree in the form of a graph i.e. Adjancent list
- Apply DFS and use an array to store the number of subordinates
- Idea is to go to the extreme left and right and while go backing or returning keep up the result
	#Subordinates(Parent) = 1 + #Subordinates(child)

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define SIZE 10000000 + 1

ll p[SIZE * 2];

string modifyString(string s)
{
    string to_return = "@";
    for (ll i = 0; i < s.size(); i++)
        to_return += "#" + s.substr(i, 1);

    to_return += "#$";
    return to_return;
}

string manacharsAlgorithm(const string &s)
{
    if (s.size() == 0)
        return "";

    string q = modifyString(s);

    ll c = 0, r = 0;

    for (ll i = 1; i < q.size() - 1; i++)
    {
        ll i_ = 2 * c - i;
        if (r > i)
            p[i] = min(r - i, p[i_]);

        while (q[i + 1 + p[i]] == q[i - 1 - p[i]])
            p[i]++;

        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }

    // find the longest palindrome
    ll maxLength = 0;
    ll centerIndex = 0;

    for (ll i = 1; i < q.size() - 1; i++)
        if (p[i] > maxLength)
        {
            maxLength = p[i];
            centerIndex = i;
        }

    string ans = s.substr((centerIndex - 1 - maxLength) / 2, maxLength);
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    cout << manacharsAlgorithm(s) << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}


```

* Good Substrings Codeforces (use of Rabin Karp Hashing tool)
```
/*

T(N) = O(N^2), S(N) = O(N)

Idea
====
- Use 2 for loops(nested) and traverse through all substrings
- The idea is take a counter i.e #bad_characters and check whether the #bad_characters are less than equal to k or not
- If they are exceeding for jth inner loop iteration, then we will ignore all the substrings for from [i to j, j+1, ....n], hence we will break out of the inner loop
- Otherwise we will use a hash set to store the hash value of the current substring
- NOTE: By storing only the hash value we are improving over MLE
- To calculate the hash value we will use Rabin Karp method to calculate the hash value, but the catch is that there are some test which will go wrong we are considering only one prime number to calculate the hash value
- To deal with that we will use 2 hash values for every substring, and we will store them in the set
- Finally we only have to return the size of the set

*/


#include<bits/stdc++.h>

using namespace std;

#define lli long long int

void solve()
{

    /*
    Rabin Karp Hashing Algorithm
    */

    string s, v;
    lli k;

    cin >> s >> v >> k;

    lli n = s.size();
    set<pair<lli, lli>> finder;

    for (int i = 0; i < n; i++)
    {
        lli mod = 1e9 + 7;
        lli hash1 = 0, hash2 = 0;
        lli prime1 = 31, prime2 = 29;
        lli pow1 = 1, pow2 = 1;
        lli badCount = 0;
        for (int j = i; j < n; j++)
        {

            badCount += (int)(v[s[j] - 'a'] == '0');

            if (badCount > k)
                break;
            hash1 = (hash1 + (s[j] - 'a' + 1) * pow1) % mod;
            hash2 = (hash2 + (s[j] - 'a' + 1) * pow2) % mod;

            pow1 = (pow1 * prime1) % mod;
            pow2 = (pow2 * prime2) % mod;

            finder.insert({hash1, hash2});
        }
    }

    cout << finder.size() << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);

    // int tcs = 0;
    // cin >> tcs;
    // for (int tc = 1; tc <= tcs; tc++)

    solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}

```

### Tree

* Find the number of subordinates
```
/ * T(N) = O(N), S(N) = O(N) */

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
void countSubordinates(vector<vector<int>> &adj, vector<int> &subordinates, int src)
{
    if (adj[src].size() == 0)
        return;
 
    for (auto child : adj[src])
    {
        countSubordinates(adj, subordinates, child);
        subordinates[src] += 1 + subordinates[child];
    }
 
    // int idx = 0;
    // for (auto i : subordinates)
    //     cerr << (idx++) << "->" << i << " ";
    // cerr << "\n";
}
 
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        adj[tmp].push_back(i);
    }
 
    vector<int> subordinates(n + 1, 0);
    countSubordinates(adj, subordinates, 1);
 
    for (int i = 1; i <= n; i++)
        cout << subordinates[i] << " ";
    cout << "\n";
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}

```

* Find the diameter in a graph where every node has at most 2 child

<table>
  <tr align="center">
    <td>There can be two cases, we will always store the maximum</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/56304060/138809642-1a138f43-fe1c-4f87-8458-595af4aa2c47.png" width=500 height=200></td>
  </tr>
 </table>

```
/*

T(N) = O(N), S(N) = O(N)

Idea
====
- Use a array to store the depth of each node
- Now, the idea is we have to find the max value of Depth[Parent] + Depth[Child] + 1
- Use dfs and keep updating Depth[Parent] in each node traversal


*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
void dfs(vector<int> tree[], vector<int> &depth, int src, int &ans, int p = -1)
{
    for (int ele : tree[src])
    {
        if (ele == p)
            continue;
 
        dfs(tree, depth, ele, ans, src);
        ans = max(ans, depth[src] + depth[ele] + 1);
        depth[src] = max(depth[src], depth[ele] + 1);
    }
}
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> tree[n];
    for (int i = 1; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        tree[l].push_back(r);
        tree[r].push_back(l);
    }
 
    int ans = 0;
    vector<int> depth(n, 0);
    dfs(tree, depth, 0, ans, -1);
    cout << ans << endl;
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}
```

* Kth Ancestor of a tree node

	- [Reference](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686268/Explanation-with-c%2B%2B-sample-code)
	- [Video reference](https://www.youtube.com/watch?v=oib-XsjFa-M&t=1s)
```

/* T(N) = S(N) = O(N * log*N) */

class TreeAncestor {
    int LOG = 0;
    vector<vector<int> > P;
public:
     // P[i][node] -> [node] 's [2^i]th parent
    TreeAncestor(int n, vector<int>& parent) {
        // initialize   
        while(1<<(LOG++) <=n);
        
        P.resize(LOG, vector<int>(parent.size(), -1));
        
        // 2^0
        for(int i = 0; i < parent.size(); i++){
            P[0][i] = parent[i];
        }
        
        // 2^i
        for(int i = 1; i < LOG; i++){
            for(int node = 0; node < parent.size(); node ++){
                int nodep = P[i-1][node];
                if(nodep != -1) P[i][node] = P[i-1][nodep];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < LOG; i++){
            if(k & (1 << i)){
                node = P[i][node];
                if(node == -1) return -1;
            }
        }

        return node;
    }
};
```

* Find the distance between two nodes
	- [Reference](https://www.youtube.com/watch?v=dOAxrhAUIhA&t=6s)
```
/* T(N) = S(N) = O(N * logN) */

#include <bits/stdc++.h>

using namespace std;

/*
// O(N) solution for LCA -> will give TLE
int LCA(int a, int b)
{
    // if depth of b is leser than a reverse the function arguments and call it
    if (depth[b] < depth[a])
        return LCA(b, a);

    // Find the difference between the levels/depths
    // Update b to its parent value until they are not in the same level
    int d = depth[b] - depth[a];
    while (d > 0)
    {
        b = parent[b];
        d--;
    }

    // Once they are in the same level

    // Check if they are equal
    if (a == b)
        return a;
    // Update both of them to their parent value
    while (parent[a] != parent[b])
        a = parent[a], b = parent[b];

    return parent[a];
}

*/

/*

T(N) = O( N + Q * logN), S(N) = O(N * logN)

Idea
=====
- Using binary lifting for finding the LCA
- Using DFS to calculate the depth of each node


*/

const int maxx = 2e5;
vector<vector<int>> graph(maxx);

// No of bits very essential always choose the optimal value wrt to the contest constraints
int LOG = 20;
vector<vector<int>> up(maxx, vector<int>(LOG));
vector<int> depth(maxx), visited(maxx);

void print(vector<int> v)
{
    for (auto i : v)
        cerr << i << " ";
    cerr << "\n";
}

void print(vector<vector<int>> g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cerr << i << ": ";
        print(g[i]);
    }
}

void dfs(int src)
{

    for (int child : graph[src])
    {
        if (visited[child] == 0)
        {
            visited[child] = 1;
            depth[child] = depth[src] + 1;
            // cerr << child << "->" << depth[child] << " " << src << "->" << depth[src] << "\n";
            up[child][0] = src;
            for (int i = 1; i < LOG; i++)
                up[child][i] = up[up[child][i - 1]][i - 1];
            dfs(child);
        }
    }
}

int findLCA(int a, int b)
{
    // We want level of b to be always lower or equal to a
    if (depth[a] > depth[b])
        return findLCA(b, a);

    int diff = depth[b] - depth[a];
    for (int i = LOG - 1; i >= 0; i--)
        if (diff & (1 << i))
            b = up[b][i];

    if (a == b)
        return a;

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i], b = up[b][i];
        }
    }
    return up[a][0];
}

void solve()
{
    int n, q, a, b;
    cin >> n >> q;
    graph = vector<vector<int>>(n);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        // if (a > b)
        //     swap(a, b);
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // cerr << "GRAPH\n";
    // print(graph);
    depth.resize(n, 0);
    visited.resize(n, 0);

    visited[0] = 1;
    dfs(0);

    // cerr << "Depths\n";
    // for (int i = 0; i < n; i++)
    //     cerr << i << "->" << depth[i] << "\n";

    while (q--)
    {
        cin >> a >> b;
        a--, b--;
        int lca = findLCA(a, b);
        // cerr << a << " " << b << " " << lca << "\n";
        cout << (depth[a] + depth[b] - 2 * depth[lca]) << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);

    solve();
}
```

### Graph

* Counting Rooms
```
#include <bits/stdc++.h>

using namespace std;

/*

T(N) = O(N), S(N) = O(N)

Idea
=====
- Simply count the connected components
- Use dfs to traverse over the graph
- Then the nodes which are not traversed in the last dfs calls
represents a separate component

*/

const int maxx = 1e3 + 1;
vector<vector<char>> graph(maxx, vector<char>(maxx));
vector<vector<bool>> visited(maxx, vector<bool>(maxx));

vector<int> xMoves = {-1, 0, 1, 0};
vector<int> yMoves = {0, -1, 0, 1};

int n, m;

bool isValid(int x, int y)
{
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
        return false;

    if (visited[x][y] || graph[x][y] == '#')
        return false;

    return true;
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int newX = x + xMoves[i];
        int newY = y + yMoves[i];
        if (isValid(newX, newY))
        {
            dfs(newX, newY);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.' and visited[i][j] == false)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);

    solve();
}
```

* Labyrithn
	- [Reference](https://www.youtube.com/watch?v=5pSMCfNR08U)
```
#include <bits/stdc++.h>

using namespace std;

/*

T(N) = O(N), S(N) = O(N)

Idea
=====
- Simply count the connected components
- Use bfs to traverse over the graph
- Now once we reached the 'B' we will trace back the path

*/

const int maxx = 1e3 + 1;
vector<vector<char>> graph(maxx, vector<char>(maxx));
vector<vector<char>> directions(maxx, vector<char>(maxx));
vector<vector<bool>> visited(maxx, vector<bool>(maxx));

// Wrt rows and cols
vector<int> aMoves = {0, -1, 0, 1};
vector<int> bMoves = {-1, 0, 1, 0};
vector<char> directionsName = {'L', 'U', 'R', 'D'};
vector<char> path;

int n, m;

bool isValid(int x, int y)
{
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
        return false;

    if (visited[x][y] || graph[x][y] == '#')
        return false;

    return true;
}

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int a = q.front().first, b = q.front().second;
        q.pop();

        if (graph[a][b] == 'B')
        {
            while (true)
            {
                path.push_back(directions[a][b]);

                // T(N) for this is O(4) ~ O(1)
                for (int i = 0; i < 4; i++)
                {
                    if (directionsName[i] == path.back())
                    {
                        // Tracing back the path
                        a += -1 * aMoves[i];
                        b += -1 * bMoves[i];
                    }
                }

                if (a == x and b == y)
                    break;
            }

            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int newA = a + aMoves[i];
            int newB = b + bMoves[i];

            if (isValid(newA, newB))
            {
                directions[newA][newB] = directionsName[i];
                q.push({newA, newB});
                visited[newA][newB] = true;
            }
        }
    }

    return false;
}

void solve()
{
    cin >> n >> m;
    int startX, startY;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                startX = i, startY = j;
            }
        }
    }

    if (bfs(startX, startY))
    {
        cout << "YES\n";
        cout << path.size() << "\n";
        while (path.size() > 0)
        {
            cout << path.back();
            path.pop_back();
        }
    }
    else
        cout << "NO\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);

    solve();
}
```

* Djisktra Algorithm
```
/*
T(N) = O(V + E*logV), S(N) = O(N)

Idea to improve time complexity is to use visited array

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void countDistance(ll n, vector<pair<int, int>> adj[], vector<bool> &visited, ll &ans, ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distance(n, LLONG_MAX);

    pq.push({0, src});
    distance[src] = 0;

    while (pq.empty() == false)
    {
        ll parent = pq.top().second;
        pq.pop();

        if (visited[parent])
            continue;
        visited[parent] = true;

        for (auto child : adj[parent])
        {
            ll childNode = child.first, weight = child.second;
            if (distance[childNode] > distance[parent] + weight)
            {
                distance[childNode] = distance[parent] + weight;
                pq.push({distance[childNode], childNode});
            }
        }
    }

    for (ll i = 0; i < n; i++)
        cout << distance[i] << " ";
    cout << "\n";
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (ll i = 0; i < m; i++)
    {
        ll v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;

        adj[v].push_back({u, w});
    }

    ll ans = LLONG_MAX;
    vector<bool> visited(n, false);
    countDistance(n, adj, visited, ans, 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}

```


### Disjoint set DS
	
* Disjoiny set union
	- [Reference](https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/)
```
/* T(N) = O(N * logN), S(N) = O(N) */
const int maxx = 1e3 + 1;
vector<int> v(maxx), sizes(maxx, 0);
int n, m;

int parent(int x)
{
    while (x != v[x])
    {
        v[x] = v[v[x]];
        x = v[x];
    }

    return x;
}

void makeUnion(int x, int y)
{
    x = parent(x);
    y = parent(y);

    if (sizes[x] < sizes[y])
    {
        v[x] = v[y];
        sizes[y] += sizes[x];
        sizes[x] = 0;
    }
    else
    {
        v[y] = v[x];
        sizes[x] += sizes[y];
        sizes[y] = 0;
    }
}

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
        sizes[i] = 1;
    }
}

void solve()
{
    cin >> n >> m;
    initialize(n);

    print(sizes);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        makeUnion(x, y);

        print(sizes);
        vector<int> tmp;
        for (int i = 0; i < n; i++)
        {
            if (sizes[i] != 0)
                tmp.push_back(sizes[i]);
        }

        sort(tmp.begin(), tmp.end());
        for (auto i : tmp)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}
```


### Segment Trees

* Minimum Range Queries

<table>
  <tr align="center">
    <td>Tree Look</td>
    <td>MAX 4N logic</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/56304060/138846893-55c3e401-34b9-49ab-9019-64ec5358273f.png" width=500 height=200></td>
    <td><img src="https://user-images.githubusercontent.com/56304060/138846905-99edfd76-72da-4daa-ae70-98917bda7086.png" width=500 height=200></td>
  </tr>
 </table>


```
/*

T(N) = O(Q * logN), S(N) = O(4*N) = O(N), where Q = No of queries
Idea
====
- We will contruct segment tree to answer minimum range query
- It will have at max 4*N total nodes (mathematically proven)
- It will have two operation, one is build and another is to answer the query
- Same logic can be used for answering sum queries and maximum range queries

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void buildSegmentTree(vector<int> &v, vector<int> &segTree, int idx, int low, int high)
{

    if (low == high)
    {
        segTree[idx] = v[low];
        return;
    }
    int mid = (low + high) >> 1;
    buildSegmentTree(v, segTree, 2 * idx + 1, low, mid);
    buildSegmentTree(v, segTree, 2 * idx + 2, mid + 1, high);

    // parent storing the minimum of both of its child
    segTree[idx] = min(segTree[2 * idx + 1], segTree[2 * idx + 2]);
}

int ansQueries(vector<int> &segTree, int idx, int low, int high, int ql, int qr)
{
    // If range query completely lies between current node's range
    if (low >= ql and high <= qr)
        return segTree[idx];

    // If the range query doesnot lie between current node's range
    if (high < ql || low > qr)
        return INT_MAX;

    // If there is a partial overlap
    int mid = (low + high) >> 1;
    int left = ansQueries(segTree, 2 * idx + 1, low, mid, ql, qr);
    int right = ansQueries(segTree, 2 * idx + 2, mid + 1, high, ql, qr);

    return min(left, right);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> segTree(4 * n);
    buildSegmentTree(v, segTree, 0, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int ql, qr;
        cin >> ql >> qr;

        // Answering queries by segement trees
        ql--;
        qr--;
        cout << ansQueries(segTree, 0, 0, n - 1, ql, qr) << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}


```

* Dynamic Range Queries

![image](https://user-images.githubusercontent.com/56304060/138940421-ebd1acae-4b62-47dd-892e-85c27ed160b5.png)

```
/*

T(N) = O(Q * logN), S(N) = O(N)

Idea
====
- Update the value in the array at the given position
- In the segment will implement an update function that wil update the values of at most logN nodes/array element
- We will first come to the parent node and we will check whether the current node's range contains the required index number or not
- If it does we will find the mid value of the range it represents then we will check whether required index lies in the left half or right half
- Once, we have reached a leaf node then we will update the segment tree idx value with the array's updated value
- The while returning we will backtrack to the parents value and update its value

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void buildSegTree(vector<ll> &v, vector<ll> &segTree, int idx, int low, int high)
{
    if (low == high)
    {
        segTree[idx] = v[low];
        return;
    }

    ll mid = (low + high) >> 1;
    buildSegTree(v, segTree, 2 * idx + 1, low, mid);
    buildSegTree(v, segTree, 2 * idx + 2, mid + 1, high);

    segTree[idx] = min(segTree[2 * idx + 1], segTree[2 * idx + 2]);
}

void update(vector<ll> &v, vector<ll> &segTree, int idx, int low, int high, int k)
{
    if (low == high)
    {
        segTree[idx] = v[k];
        return;
    }

    ll mid = (low + high) >> 1;

    if (k <= mid)
        update(v, segTree, 2 * idx + 1, low, mid, k);
    else
        update(v, segTree, 2 * idx + 2, mid + 1, high, k);

    segTree[idx] = min(segTree[2 * idx + 1], segTree[2 * idx + 2]);
}

ll ansQueries(vector<ll> &segTree, int idx, int low, int high, int ql, int qh)
{
    // If completely overlapping
    if (low >= ql and high <= qh)
        return segTree[idx];

    // If not overlapping at all
    if (low > qh or high < ql)
        return INT_MAX;

    // If there is a parital overlap
    ll mid = (low + high) >> 1;
    ll left = ansQueries(segTree, 2 * idx + 1, low, mid, ql, qh);
    ll right = ansQueries(segTree, 2 * idx + 2, mid + 1, high, ql, qh);

    return min(left, right);
}

void solve()
{

    ll n, queries;
    cin >> n >> queries;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<ll> segTree(4 * n);
    buildSegTree(v, segTree, 0, 0, n - 1);

    while (queries--)
    {
        ll k, a, b;
        cin >> k >> a >> b;

        a--;
        if (k == 2)
        {
            b--;
            cout << ansQueries(segTree, 0, 0, n - 1, a, b) << "\n";
        }
        else
        {
            v[a] = b;
            update(v, segTree, 0, 0, n - 1, a);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}

```

* Range updates and sums
	- [Reference](https://cp-algorithms.com/data_structures/segment_tree.html)
```
#include<bits/stdc++.h>
using namespace std;

template<typename... T>
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}

#define int long long
#define pb push_back
#define F first
#define S second

const int inf = 1LL<<62;
const int md = 1000000007;

pair<int,int> seg[1000005];
int mark[1000005];

void push(int k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].F = seg[2*k + 1].F = seg[k].F/2;
        seg[2*k].S = seg[2*k + 1].S = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}

void update(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].S += v;
        return;
    }
    int h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].F += h*v;
    int d = (x+y)/2;
    update(v, a, b, 2*k, x, d);
    update(v, a, b, 2*k + 1, d + 1, y);
}
int assign(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return seg[k].F + (y - x + 1)*seg[k].S;
    if (a <= x && b >= y) {
        seg[k].F = (y-x+1)*v;
        seg[k].S = 0;
        mark[k] = 1; 
        return seg[k].F;
    }
    push(k); 
    int d = (x+y)/2;
    seg[2*k].S += seg[k].S,  seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    seg[k].F = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].F;

}
int sum(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].F + (y-x+1)*seg[k].S;
    }
    push(k); 
    seg[k].F += (y-x+1)*seg[k].S;
    seg[2*k].S += seg[k].S, seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    int d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}
void solve(){
    int n,q; cin>>n>>q;
    int nn =n;
    n = 1<<(int)ceil(log2(n));
    for (int i = 0; i< nn; i++) {
        int x; cin>>x;
        update(x,i,i,1,0,n-1);
    }
    while (q--) {
        int z;
        cin>>z;
        if (z == 1) {
            int a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            update(x,a,b,1,0,n-1);
        }
        else if (z == 2) {
            int a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            assign(x,a,b,1,0,n-1);
        }
        else {
            int a,b;
            cin>>a>>b; a--, b--;
            cout<<sum(a,b,1,0,n-1)<<'\n';
        }
    }
}    
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }
}
```
