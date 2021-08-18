// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


#define ll long long

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long hist[], int n)
    {
        // Your code here
        stack<ll> s;
        
        ll maxx = 0, tp, at;
        
        int i = 0;
        while(i<n)
        {
            if(s.empty() || hist[s.top()] <= hist[i]) s.push(i++);
            
            else
            {
                tp = s.top();
                s.pop();
                
                at = hist[tp]*(s.empty() ? i : i - s.top() - 1);
                
                if(maxx < at) maxx = at;
            }
        }
        
        while(!s.empty())
        {
            
            tp = s.top();
            s.pop();
            
            at = hist[tp]*(s.empty() ? i : i - s.top() - 1);
            
            if(maxx < at) maxx = at;
        }
        
        
        return maxx;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends