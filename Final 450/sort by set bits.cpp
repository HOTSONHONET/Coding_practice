// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    
    int setBits(int n){
        int cnt = 0;
        while(n)
        {
            if(n&1) cnt++;
            n >>= 1;
        }
        
        return cnt;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        multimap<int, int> mmap;
        for(int i = 0; i<n; i++)
        {
            mmap.insert({(-1)*setBits(arr[i]), arr[i]});
        }
        
        int j = 0;
        for(auto i: mmap){
            arr[j] = i.second;
            j++;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends