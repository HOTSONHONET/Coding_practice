// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
public:

    
	int minSwaps(vector<int>&arr){
	    // Code here
	   
	   int n = arr.size();
	   vector<pair<int,int>> vec(n);
     
        for(int i=0;i<n;i++)
        {
            vec[i].first=arr[i];
            vec[i].second=i;
        }
     
        // Sort the vector w.r.t the first
        // element of pair
        sort(vec.begin(),vec.end());
     
        int ans=0,c=0,j;
     
        for(int i=0;i<n;i++)
        {  
            // If the element is already placed
            // correct, then continue
            if(vec[i].second==i)
                continue;
            else
            {
                // swap with its respective index
                swap(vec[i].first,vec[vec[i].second].first);
                swap(vec[i].second,vec[vec[i].second].second);
            }
             
            // swap until the correct
            // index matches
            if(i!=vec[i].second)
                --i;
             
            // each swap makes one element
            // move to its correct index,
            // so increment answer
            ans++;
        }
     
        return ans;
    	   
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends