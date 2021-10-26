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

* There can be two cases, we will always store the maximum
![image](https://user-images.githubusercontent.com/56304060/138809642-1a138f43-fe1c-4f87-8458-595af4aa2c47.png)

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

### Graph

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
