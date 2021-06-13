// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    
	    vector<int> pi(s.length() + 1, 0);
        pi[0] = -1;
        int k = -1;
              
        for (int i = 1; i <= s.length(); i++) {
            while(k >= 0 && s[k] != s[i - 1]) k = pi[k];
            pi[i] = ++k;
        }
        
        string res = s.substr(0, pi[s.length()]);
        return res.length();

	    
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends 