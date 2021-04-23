// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n = s.length();
    
    if (n%2 != 0) return -1;
    
    int l = 0, r = 0, ans;
    
    for (int i = 0; i<n; i++){
        if (s[i] == '{') l++;
        else{
            if(l == 0) r++;
            else l--;
        }
    }
    
    ans = (l+r)/2 + l%2;
    return ans;
    
    
    
}