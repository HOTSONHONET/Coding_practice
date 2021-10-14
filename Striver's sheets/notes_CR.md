# CR sheet solution

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
