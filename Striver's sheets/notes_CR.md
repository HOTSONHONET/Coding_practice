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
