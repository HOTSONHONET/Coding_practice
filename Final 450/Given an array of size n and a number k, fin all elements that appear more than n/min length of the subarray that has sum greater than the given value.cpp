// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here 
        int ans = n+1;
        int l = 0, r = 0, s = 0;
        while(l<=r and r<n){
            while(s<=x and r<n){
                s+=arr[r++];
            }

            while(s>x and l<r){
                ans = min(ans, r-l);
                s -= arr[l];
                l++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends