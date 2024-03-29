// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        
        // your code here
        map<int, int> counter;
        for(int i = 0; i<size; i++){
            counter[arr[i]]++;
        }
        
        int ans = -1;
        for(int i = 0; i<size; i++){
            if (counter[arr[i]] > size/2) ans = arr[i];
        }
        
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends