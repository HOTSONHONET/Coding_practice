// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int search(vector<int>& nums, int l, int r, int key)
    {
        int index = -1;
        while (l <= r) 
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= key)
                r = mid - 1;
            else 
            {
                l = mid + 1;
                if (index == -1 || nums[index] >= nums[mid])
                    index = mid;
            }
        }
        return index;
    }
    
    
    vector<int> nextPermutation(int n, vector<int> nums){

        int i;
        for(i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
                break;
        }
        
        if(i < 0)
            reverse(nums.begin(), nums.end());
        
        else
        {
            int index = search(nums, i + 1, n - 1, nums[i]);
            swap(nums[i], nums[index]);
            reverse(nums.begin() + i + 1, nums.end());
        }
        
        
        return nums;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends