// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int curSum = 0, maxSum = 0;
	    for(int i = 0; i<S.size(); i++)
	    {
	        curSum += (S[i] == '0') ? 1:-1;
	        
	        if(curSum < 0) curSum = 0;
	        maxSum = max(maxSum, curSum);
	    }
	    
	    return (maxSum == 0) ? -1 : maxSum;
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
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends