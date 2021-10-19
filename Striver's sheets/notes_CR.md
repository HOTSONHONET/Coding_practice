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

*T(N) = O(1), [Reference](https://www.youtube.com/watch?v=-GUstRI69PI)
```
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
