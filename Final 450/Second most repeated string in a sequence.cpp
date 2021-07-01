// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string seq[], int n)
    {
        //code here.
        unordered_map<string, int> occ;
        for (int i = 0; i < n; i++)
            occ[seq[i]]++;
     
        // find the second largest occurrence
        int first_max = INT_MIN, sec_max = INT_MIN;
        for (auto it = occ.begin(); it != occ.end(); it++) {
            if (it->second > first_max) {
                sec_max = first_max;
                first_max = it->second;
            }
     
            else if (it->second > sec_max &&
                     it->second != first_max)
                sec_max = it->second;
        }
     
        // Return string with occurrence equals
        // to sec_max
        for (auto it = occ.begin(); it != occ.end(); it++)
            if (it->second == sec_max)
                return it->first;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends