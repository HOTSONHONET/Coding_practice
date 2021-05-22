// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a+n);
        int ans = 0;
        for(int i = 0; i<n ;i++){
            if(a[i] < 0 and k>0){
                a[i] = -a[i];
                k--;
            }
        }
        for(int i = 0; i<n; i++){
            ans += a[i];
        }
        
        long long int x = *min_element(a, a+n);
        if(k&1) ans -= 2*x;
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends