// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    string start_0 = "", start_1 = "";
    
    int n = S.length();
    for(int i = 0; i<n; i++){
        (i%2==0) ? start_0 += '0' : start_0 += '1';
        (i%2==0) ? start_1 += '1' : start_1 += '0';
    }
    
    int min_cost_0 = 0, min_cost_1 = 0;
    for(int i = 0; i<n; i++){
        if(start_0[i] != S[i]) min_cost_0++;
        if(start_1[i] != S[i]) min_cost_1++;
    }
    
    return min(min_cost_0, min_cost_1);
}