// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_set<int> uset;
      for(int i = 0; i<n; i++){
          uset.insert(arr[i]);
      }
      
      int ans = INT_MIN, cnt;
      for(int i = 0; i<n; i++){
          if (uset.find(arr[i] - 1) == uset.end()){
              int cur_val = arr[i];
              cnt = 1;
              while(uset.find(cur_val + 1) != uset.end()){
                  cnt++;
                  cur_val++;
              }
              ans = max(ans, cnt);
              
          }
      }
      
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends